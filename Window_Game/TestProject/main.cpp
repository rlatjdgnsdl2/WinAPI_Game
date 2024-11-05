#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "PreCompile.h"

const int DUNGEON_WIDTH = 60;
const int DUNGEON_HEIGHT = 40;
const int MAX_ROOMS = 4;
const int MAX_ROOM_SIZE = 10;
const int MIN_ROOM_SIZE = 3;

enum TileType {
    WALL = 1,
    FLOOR = 0
};

struct Room {
    int x, y, width, height;

    bool intersects(const Room& other) const {
        return (x < other.x + other.width && x + width > other.x &&
            y < other.y + other.height && y + height > other.y);
    }

    bool isWithinBounds() const {
        return (x >= 1 && y >= 1 && x + width < DUNGEON_WIDTH - 1 && y + height < DUNGEON_HEIGHT - 1);
    }

    std::pair<int, int> center() const {
        return { x + width / 2, y + height / 2 };
    }
};

void initializeDungeon(std::vector<std::vector<int>>& dungeon) {
    for (auto& row : dungeon) {
        std::fill(row.begin(), row.end(), WALL);
    }
}

void createRoom(std::vector<std::vector<int>>& dungeon, const Room& room) {
    for (int i = room.y; i < room.y + room.height; ++i) {
        for (int j = room.x; j < room.x + room.width; ++j) {
            dungeon[i][j] = FLOOR;
        }
    }
}

Room generateRandomRoom() {
    int width = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1);
    int height = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1);
    int x = rand() % (DUNGEON_WIDTH - width - 1) + 1;
    int y = rand() % (DUNGEON_HEIGHT - height - 1) + 1;
    return { x, y, width, height };
}

std::vector<Room> placeRooms(std::vector<std::vector<int>>& dungeon) {
    std::vector<Room> rooms;
    int roomCount = 0;

    while (roomCount < MAX_ROOMS) {
        Room newRoom = generateRandomRoom();

        if (newRoom.isWithinBounds()) {
            bool overlaps = false;
            for (const auto& room : rooms) {
                if (newRoom.intersects(room)) {
                    overlaps = true;
                    break;
                }
            }

            if (!overlaps) {
                createRoom(dungeon, newRoom);
                rooms.push_back(newRoom);
                ++roomCount;
            }
        }
    }

    return rooms;
}

// 시작과 끝 점을 무작위 경로로 연결
void createRandomPathCorridor(std::vector<std::vector<int>>& dungeon, std::pair<int, int> start, std::pair<int, int> end) {
    int x = start.first;
    int y = start.second;

    while (x != end.first || y != end.second) {
        dungeon[y][x] = FLOOR;

        // X 또는 Y 방향으로 무작위로 이동
        if (rand() % 2 == 0) {
            // X 방향 이동
            if (x < end.first) x++;
            else if (x > end.first) x--;
        }
        else {
            // Y 방향 이동
            if (y < end.second) y++;
            else if (y > end.second) y--;
        }
    }

    // 마지막 도착점 표시
    dungeon[end.second][end.first] = FLOOR;
}

void connectRooms(std::vector<std::vector<int>>& dungeon, const std::vector<Room>& rooms) {
    for (size_t i = 1; i < rooms.size(); ++i) {
        auto center1 = rooms[i - 1].center();
        auto center2 = rooms[i].center();
        createRandomPathCorridor(dungeon, center1, center2);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::vector<std::vector<int>> dungeon(DUNGEON_HEIGHT, std::vector<int>(DUNGEON_WIDTH, WALL));
    initializeDungeon(dungeon);

    std::vector<Room> rooms = placeRooms(dungeon);

    // 방들을 통로로 연결
    connectRooms(dungeon, rooms);

    // 던전 출력 (디버그용)
    for (const auto& row : dungeon) {
        for (int tile : row) {
            std::cout << (tile == WALL ? '#' : '.');
        }
        std::cout << '\n';
    }

    return 0;
}
