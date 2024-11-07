#pragma once



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



