#pragma once

class Room
{
private:
	int startX, startY;
	int width, height;
	
public:
	Room(int startX, int startY, int width, int height);
	inline int getStartX() const { return startX; }
	inline int getStartY() const { return startY; }
	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }	
};

