#pragma once



struct Room {
    int x, y, width, height;
    bool isValid() const {
        // ���� ��ȿ�Ϸ��� �ʺ�� ���̰� 0���� Ŀ�� ��
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



