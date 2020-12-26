class CAppBoard
{
private:
	const static int C_INT_BOARD_LEN = 3;

	//0 intial state
	//1 First player
	//2 Second player
	int m_BoardMatrix[C_INT_BOARD_LEN][C_INT_BOARD_LEN];
public:
	CAppBoard();
	~CAppBoard();
	void DrawBoard();
};

CAppBoard::CAppBoard()
{
	//init the board
	int i, j; 
	for (i = 0; i < C_INT_BOARD_LEN; i++)
		for (j = 0; j < C_INT_BOARD_LEN; i++)
		{
			m_BoardMatrix[i][j] = 0;
		}
}


CAppBoard::~CAppBoard()
{
	//todo 
}

void CAppBoard::DrawBoard()
{
	//todo
}