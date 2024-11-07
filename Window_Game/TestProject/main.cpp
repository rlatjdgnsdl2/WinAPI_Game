#include <iostream>
#include <vector>
#
#include <cstdlib>
#include <ctime>
#include "PreCompile.h"

struct Room {
    int x, y, width, height;
};

struct Node {
    int x, y, width, height;
    Room room;
    Node* left = nullptr;
    Node* right = nullptr;

    bool isLeaf() const { return left == nullptr && right == nullptr; }
};

// 노드가 나눠지기 위한 최소 크기
const int MIN_SIZE = 10;
const int MAX_SIZE = 20;

class Dungeon {
public:
    Dungeon(int width, int height) : width(width), height(height) {
        map = std::vector<std::vector<int>>(height, std::vector<int>(width, 1));
        srand(time(0));
    }

    void generate() {
        Node* root = new Node{ 0, 0, width, height };
        split(root);
        createRooms(root);
        connectRooms(root);
    }

    void print() {
        for (const auto& row : map) {
            for (int cell : row) {
                std::cout << (cell == 0 ? "." : "#");
            }
            std::cout << "\n";
        }
    }

private:
    int width, height;
    std::vector<std::vector<int>> map;

    bool split(Node* node) {
        if (node->width < MIN_SIZE || node->height < MIN_SIZE)
            return false;

        bool splitHorizontally = (node->width < node->height) || (rand() % 2);
        int max = (splitHorizontally ? node->height : node->width) - MIN_SIZE;

        if (max <= MIN_SIZE)
            return false;

        int splitPos = MIN_SIZE + rand() % (max - MIN_SIZE);
        if (splitHorizontally) {
            node->left = new Node{ node->x, node->y, node->width, splitPos };
            node->right = new Node{ node->x, node->y + splitPos, node->width, node->height - splitPos };
        }
        else {
            node->left = new Node{ node->x, node->y, splitPos, node->height };
            node->right = new Node{ node->x + splitPos, node->y, node->width - splitPos, node->height };
        }

        split(node->left);
        split(node->right);
        return true;
    }

    void createRooms(Node* node) {
        if (node->isLeaf()) {
            int roomWidth = MIN_SIZE + rand() % (node->width - MIN_SIZE);
            int roomHeight = MIN_SIZE + rand() % (node->height - MIN_SIZE);
            int roomX = node->x + rand() % (node->width - roomWidth);
            int roomY = node->y + rand() % (node->height - roomHeight);

            node->room = { roomX, roomY, roomWidth, roomHeight };
            for (int i = roomY; i < roomY + roomHeight; ++i) {
                for (int j = roomX; j < roomX + roomWidth; ++j) {
                    map[i][j] = 0;
                }
            }
        }
        else {
            if (node->left) createRooms(node->left);
            if (node->right) createRooms(node->right);
        }
    }

    void connectRooms(Node* node) {
        if (!node->left || !node->right) return;

        Room room1 = getRoom(node->left);
        Room room2 = getRoom(node->right);

        int startX = room1.x + room1.width / 2;
        int startY = room1.y + room1.height / 2;
        int endX = room2.x + room2.width / 2;
        int endY = room2.y + room2.height / 2;

        while (startX != endX) {
            map[startY][startX] = 0;
            startX += (startX < endX) ? 1 : -1;
        }
        while (startY != endY) {
            map[startY][startX] = 0;
            startY += (startY < endY) ? 1 : -1;
        }

        connectRooms(node->left);
        connectRooms(node->right);
    }

    Room getRoom(Node* node) {
        if (node->isLeaf()) return node->room;
        if (node->left) return getRoom(node->left);
        if (node->right) return getRoom(node->right);
        return node->room;
    }
};

int main() {
    Dungeon dungeon(60, 40);
    dungeon.generate();
    dungeon.print();
    return 0;
}
