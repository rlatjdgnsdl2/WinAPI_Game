#pragma once



struct Room {
    int x, y, width, height;
    bool isValid() const {
        // 방이 유효하려면 너비와 높이가 0보다 커야 함
        return width > 0 && height > 0;
    }
};


struct Node {
    int x, y, width, height;
    Room room;
    Node* left = nullptr;
    Node* right = nullptr;

    bool isLeaf() const { return left == nullptr && right == nullptr; }

    ~Node() {
        delete left;
        delete right;
    }
    
};



