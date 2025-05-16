#include <iostream>
#include <vector>

using namespace std;

/*
	목표: 배열의 크기를 수동으로 변경하는 코드
		
		  "자동" vector
*/

/*
	int 10개 배열로 저장한다.
	배열의 특징 : 크기가 고정. 만들 때 크기를 정해줘야 한다. 40바이트의 공간을 확보해야한다.
	41바이트 떨어진 공간에서 메모리를 접근 - 문제가 발생
*/

// 배열의 크기를 N 받을 수 있게 코드를 추가해보기
// String, char, double 코드 추가해보기

/*
	vector 클래스의 기능
	 push_back	  : 벡터의 끝에 데이터를 추가한다. (존재하는 데이터)
	 size()		  : 벡터의 길이를 반환한다.
	 emplace_back : 백터의 끝에 직접 생성한 데이터 추가
	 pop_back()	  : 가장 뒤의 데이터 하나를 지운다
	 empty()	  : 벡터의 크기가 0이면 true, 아니면 false
	 insert()	  : 주어진 위치에 데이터를 입력한다. vec.insert(vec.begin() + 2 , 10);
	 erase()	  : 주어진 위치에 데이터를 제거한다. vec.erase(vec.begin())
*/

/*
	vec.0 = 1_슬라임  <- erase 해본다던가
*/



template<typename T, int N>
void MakeArray(T*& ptr, T value)
{
	// 연결된 메모리를 해제
	// 배열의 크기를 수동으로 만들고 보여주는 예제 코드
	delete[] ptr; // delete에 [] 하면 배열 삭제
	ptr = new T[N];

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}

	cout << endl;
}

class MonsterHandle
{

};

// 클래스 이름 Monster 번호, 이름
class Monster 
{
private:
	int _num;
	string _name;

public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name) : 
		_num(num), _name(name) {}

	int get_num() const { return _num; }
	string get_name() const { return _name; }

	// "cout<< Monster 출력했을 때의 오류"
	// friend: 외부 클래스의 private에 접근할 수 있게 해주는 키워드 (객체지향 방식에 위배되긴 한다.)
	friend ostream& operator<<(ostream& os, Monster &obj) // obj 주소 참조하여 반환값을 os로 표시
	{
		os << "NO." << obj._num << "_" << obj._name << "";
		return os;
	}

};

template<typename T>
void Show(vector<T>& vec) 
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}

int main() 
{
	// 수동으로 배열의 크기를 변경하고 생성하는 함수 템플릿
	// 클래스 템플릿
	// 인벤토리 10개. -> 11개	(Array 10개.) -> 

	int* aPtr = new int[10];
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample(0, "고블린");
	Monster pika(25, "피카츄");

	MakeArray<int,10>(aPtr, 0); // aPtr 크기 넘으면 터진다.
	MakeArray<double, 15>(bPtr, 0.1);
	MakeArray<string, 10>(cPtr, "owo");
	MakeArray<Monster, 10>(dPtr, sample);
	MakeArray<Monster, 5>(dPtr, pika);

	int input;

	cout << "배열의 크기를 입력해 주세요 : " << endl;

	// vector로 쉽게 배열을 생성하고 출력하기


	cout << "vector 사용 예제 " << endl;

	vector<int> nums; // vector int를 저장하는 가변배열 클래스. (배열 크기가 가변한다.)


	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	Show<int>(nums);

	vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "고블린");
	monsterDatabase.emplace_back(2, "골렘");
	monsterDatabase.emplace_back(3, "슬라임");
	monsterDatabase.clear();
	//monsterDatabase.pop_back();
	//monsterDatabase.pop_back(); // push pop 개념 생각하면 된다.
	//monsterDatabase.pop_back(); 

	Show<Monster>(monsterDatabase);

	if(!monsterDatabase.empty())
	{
		cout << "데이터가 있습니다." << endl;
	}
	else
	{
		cout << "데이터가 없습니다." << endl;
	}


	cout << "int형 데이터." << endl;
	vector<int> number;
	
	number.push_back(1);
	number.push_back(2);
	number.push_back(3);
	Show<int>(number);
	number.pop_back();
	Show<int>(number);
	number.insert(number.begin() + 0, 5); // 배열순서 [0][1][2] 순서를 따라간다.
	Show<int>(number);
	number.erase(number.begin() + 0);
	Show<int>(number);
	number.clear();

	cout << "그외 데이터." << endl;

	vector<double> dnumber;
	vector<string> keyword;
	vector<Monster> newMonster;

	for (int i = 0; i < 10; i++) 
	{
		number.push_back(0);
		dnumber.push_back(0.1);
		keyword.push_back("AAA");
		monsterDatabase.push_back(sample);
	}
	Show<int>(number);
	Show<double>(dnumber);
	Show<string>(keyword);
	Show<Monster>(monsterDatabase);

	// int 타입을 저장하는 배열을 vector 컨테이너에 저장하는 코드를 작성하시오.
	vector<int> nnn;
	nnn.push_back(1);
	nnn.pop_back();
	nnn.size();

	// 테트리스. 4가지 블럭
	// vector<Block> blocks;

	// 4가지 직업. 전사, 마법사, 도적, 궁수
	// vector<GameClass> gameClasses;

	// 객체. Monster
	// 관리하는 클래스 MonsterManager
	// vector<Monster>


}
