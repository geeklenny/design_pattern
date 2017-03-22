
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//������ɫ
enum PieceColor {BLACK, WHITE};
//����λ��
struct PiecePos
{
	int x;
	int y;
	PiecePos(int a, int b): x(a), y(b) {}
};
//���Ӷ���
class Piece
{
protected:
	PieceColor m_color; //��ɫ
public:
	Piece(PieceColor color): m_color(color) {}
	~Piece() {}
	virtual void Draw() {}
};
class BlackPiece: public Piece
{
public:
	BlackPiece(PieceColor color): Piece(color) {}
	~BlackPiece() {}
	void Draw() { cout<<"����һ�ź���\n"; }
};
class WhitePiece: public Piece
{
public:
	WhitePiece(PieceColor color): Piece(color) {}
	~WhitePiece() {}
	void Draw() { cout<<"����һ�Ű���\n";}
};

class PieceBoard
{
private:
	vector<PiecePos> m_vecPos; //������ӵ�λ��
	Piece *m_blackPiece;       //�������� 
	Piece *m_whitePiece;       //��������
	string m_blackName;
	string m_whiteName;
public:
	PieceBoard(string black, string white): m_blackName(black), m_whiteName(white)
	{
		m_blackPiece = NULL;
		m_whitePiece = NULL;
	}
	~PieceBoard() { delete m_blackPiece; delete m_whitePiece;}
	void SetPiece(PieceColor color, PiecePos pos)
	{
		if(color == BLACK)
		{
			if(m_blackPiece == NULL)  //ֻ��һ�ź���
				m_blackPiece = new BlackPiece(color);	
			cout<<m_blackName<<"��λ��("<<pos.x<<','<<pos.y<<")";
			m_blackPiece->Draw();
		}
		else
		{
			if(m_whitePiece == NULL)
				m_whitePiece = new WhitePiece(color);
			cout<<m_whiteName<<"��λ��("<<pos.x<<','<<pos.y<<")";
			m_whitePiece->Draw();
		}
		m_vecPos.push_back(pos);
	}
};


int main()
{
	PieceBoard pieceBoard("A","B");
	pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
	pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
	pieceBoard.SetPiece(BLACK, PiecePos(16, 4));
	pieceBoard.SetPiece(WHITE, PiecePos(16, 16));
}