#include "SmartMonster.h"
#include "Board.h"

SmartMonster::SmartMonster(const sf::Texture& image, sf::Vector2f position) :Monster(image, position), m_passed(SIZE)
{
}

//******************************************************
void SmartMonster::move(float time, Board& board)
{
	
	float speed = time * SMART_MONSTER_SPEED;
	m_passed += speed;
	if (m_passed >= SIZE) 
	{
		board.initBFS();
		m_direction = BFS(board.matrix(), board.BFSize());
		m_passed = 0;
	}
	moveTo(m_direction, speed, board);
}

//******************************************************
void SmartMonster::moveBack(float time)
{
	float speed = time * SMART_MONSTER_SPEED;
	MovableItem::moveBack(speed);
}

//***************************************************
bool SmartMonster::isBlocked(const Stone& stone)const
{
	return true;
}

//*****************************************************************************************
int SmartMonster::BFS(std::vector<std::vector<BFStruct>>& matBFS, sf::Vector2i sizeBFS)
{

	int i = int((getCurPosition().y - Board::m_firstPoint.y + 35) / SIZE ) ;
	int j = int((getCurPosition().x - Board::m_firstPoint.x + 35) / SIZE ) ;

	matBFS[i][j].isSorce = true;
	matBFS[i][j].isValid = false;

	std::vector<Point> queue;
	if (i > 0 && matBFS[i - 1][j].isValid)
		if (matBFS[i - 1][j].isDestination)
			return UP;
		else handleSon(Point{ i - 1 , j }, Point{ i , j }, matBFS, queue);
		
	if (i+1 < sizeBFS.y && matBFS[i + 1][j].isValid)
		if (matBFS[i + 1][j].isDestination)
			return DOWN;
		else handleSon(Point{ i + 1 , j }, Point{ i , j }, matBFS, queue);
			
	if (j > 0 && matBFS[i][j-1].isValid)
		if (matBFS[i][j-1].isDestination)
			return LEFT;
		else  handleSon(Point{ i , j - 1 }, Point{ i , j }, matBFS, queue);
			
	if (j+1 < sizeBFS.x && matBFS[i][j + 1].isValid)
		if (matBFS[i][j + 1].isDestination)
			return RIGHT;
		else  handleSon(Point{ i , j + 1 }, Point{ i , j }, matBFS, queue);
			
	int d = 0;
	
	while (queue.size() > d  && !checkSons(queue[d], matBFS, sizeBFS, queue))
		d++;
	if (queue.size() == d)
		return STAND;
	int b = queue[d].row;
	int c = queue[d].col;
	while (!matBFS[matBFS[b][c].parent.row][matBFS[b][c].parent.col].isSorce)
	{
		int temp = b;
		b = matBFS[b][c].parent.row;
		c = matBFS[temp][c].parent.col;
	}
	if (b == matBFS[b][c].parent.row)
		if (c > matBFS[b][c].parent.col)
			return RIGHT;
		else return LEFT;
	else if (b > matBFS[b][c].parent.row)
		return DOWN;
	return UP;

}

//********************************************************************
bool SmartMonster::checkSons(Point point, std::vector<std::vector<BFStruct>>& matBFS, sf::Vector2i sizeBFS, std::vector<Point>& queue)
{
	int i = point.row;
	int j = point.col;

	if (i > 0 && matBFS[i - 1][j].isValid)
		if (matBFS[i - 1][j].isDestination)
			return true;
		else  handleSon(Point{ i - 1 , j }, Point{ i , j }, matBFS, queue);

	if (i + 1 < sizeBFS.y && matBFS[i + 1][j].isValid)
		if (matBFS[i + 1][j].isDestination)
			return true;
		else  handleSon(Point{ i + 1 , j }, Point{ i , j }, matBFS, queue);

	if (j > 0 && matBFS[i][j - 1].isValid)
		if (matBFS[i][j - 1].isDestination)
			return true;
		else  handleSon(Point{ i , j - 1 }, Point{ i , j }, matBFS, queue);

	if (j + 1 < sizeBFS.x && matBFS[i][j + 1].isValid)
		if (matBFS[i][j + 1].isDestination)
			return true;
		else  handleSon(Point{ i , j + 1 }, Point{ i , j }, matBFS, queue);

	return false;
}

//***********************************************************************************
void SmartMonster::handleSon(Point son, Point parent, std::vector<std::vector<BFStruct>>& matBFS, std::vector<Point>& queue)
{
	matBFS[son.row][son.col].parent = parent;
	queue.push_back(son);
	matBFS[son.row][son.col].isValid = false;
}
