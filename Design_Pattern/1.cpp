// 1. Singleton
/* ���� ������ ������� �ʰ� ��ü�� ���� �� ���� ������ �����ϸ�, ������ ��ü�� ��𿡼����� ������ �� �ֵ��� �ϴ� ����

�̱��� ������ �̿��ϸ�, �ϳ��� �ν��Ͻ��� �޸𸮿� ����� ���� �����尡 ���ÿ� �ش� �ν��Ͻ��� �����Ͽ� ����ϰ� �� �� �־�
��û�� ���� ������ ����ϸ� ȿ���� ���� �� �ִ�.

�������� Ư¡�� Private Constructor, static method�� ����ϴ� ���̴�.

 ������ �̱��������� Gof�鵵 �������� �ʴ� ���������̸�, ��Ƽ������ ���� �浹�� �Ҿ�µ� �ǵ��ʹ� �޸� �溸�ٴ� ���� ���ٰ��Ѵ�.
*/

//#include <iostream>
//using namespace std;
//
//class Singleton {
//private: // ���� ������, ������, �Ҹ��ڸ� private�� �����Ͽ�, ����, ����� ���ϰ� ����
//	Singleton() {} // ������
//	Singleton(const Singleton& ref) {}
//	Singleton& operator=(const Singleton& ref) {}
//	~Singleton() {}
//
//public:
//	static Singleton& getInstance() // ���������� static�� ���� ���� ��ü �Ѱ����� �̱����������� �����// getIncetance() �Լ��� �����ؾ��� �����Ǵ� ���� �ʱ�ȭ�� ���
//	{
//		static Singleton s;
//		return s;
//	}
//};




/* 2. Strategy // ���� ����

	���� �߿� �˰����� ������ �� �ְ� �ϴ� ���� ����Ʈ���� ������ �����̸�, Ư�� �迭�� �˰������ �����ϰ� �� �˰����� ĸ��ȭ�Ͽ�
	�ش� �迭 �ȿ��� ��ȣ ��ü�� �����ϰ� �����.

	Ư�� ���ؽ�Ʈ���� �˰����� ������ �и��ϴ� ���� ����̴�.
	�� Ư���� ����� �����ϴµ��� �־� �پ��� �˰����� ���� �� �� �ְ� ������ �и��ϴ� ���� ���.

	��Ӻ��ٴ� ������ Ȱ���Ͽ�, ��ü�� Composition�� ���ؼ� �̸� �������� ����ڰ� �˾Ƽ�
	dynamci �ϰ� ���Ƴ��� �� �ֵ��� �ϴ� ���̴�.
	���� ������ ���ؼ� �θ� class�� ���ǿ����� Composition�� ���Ͽ� ����� ����
	�߻�Ŭ�� ��ü�� operation���� ����ϰ� �صд�.

	�ڵ��� ���뼺�� �����ְ� Ȯ�强�� ���������� ���⵵�� �԰� �ö󰡰� ���ɿ��� ���ظ� �� �� �ִ�.

*/


//#include <iostream>
//using namespace std;
//
//// �θ� Ŭ���� Duck
//class Duck {
//public:
//	QuackBehavior* quackBehavior; // ���� (composition)
//	FlyBehavior* flyBehavior; // ���� (composition)
//
//	Duck() {}
//
//	void performQuack()
//	{
//		quackBehavior->quack(); // ���� (delegation)
//	}
//	void performFly()
//	{
//		flyBehavior->fly(); // ���� (delegation)
//	}
//
//	void setFlyBehavior(FlyBehavior* fb)
//	{
//		flyBehavior = fb;	// ��ü ��ü
//	}
//
//	void setQuackBehavior(QuackBehavior* qb)
//	{
//		quackBehavior = qb;
//	}
//};
//
//// Duck�� ��ӹ޴� û�տ���(MallardDuck) Ŭ����
//class MallardDuck : public Duck
//{
//public:
//	MallardDuck()
//	{
//		setFlyBehavior(new FlyWithWings());
//		setQuackBehavior(new Quack());
//	}
//};
//
//// Duck�� ��ӹ޴� ��������(ModelDuck) Ŭ����
//class ModelDuck : public Duck
//{
//public:
//	ModelDuck()
//	{
//		setFlyBehavior(new FlyNoway());
//		setQuackBehavior(new MuteQuack());
//	}
//};
//
//// Quack Behavior Ŭ����
//class QuackBehavior {
//public:
//	virtual void quack() {}
//};
//
//class Quack : public QuackBehavior
//{
//public:
//	virtual void quack() { cout << "quack!" << endl; }
//};
//
//class MuteQuack : public QuackBehavior
//{
//public:
//	virtual void quack() { cout << "....silence!" << endl; }
//};
//
//
//// Fly Behavior Ŭ����
//class FlyBehavior {
//public:
//	virtual void fly() {}
//};
//
//class FlyWithWings : public FlyBehavior
//{
//public:
//	virtual void fly() { cout << "i can fly" << endl; }
//
//};
//
//class FlyNoway : public FlyBehavior
//{
//public:
//	virtual void fly() { cout << "i can't fly" << endl; }
//
//};
//
//int main()
//{
//	MallardDuck mallardDuck;
//	ModelDuck modelDuck;
//
//	cout << "Mallard Duck : " << endl;
//	mallardDuck.performFly();
//	mallardDuck.performQuack();
//	
//	cout << "ModelDuck Duck : " << endl;
//	modelDuck.performFly();
//	modelDuck.performQuack();
//	
//}



/*  3. Adater Pattern
�̹� �����Ǿ� �ִ� �Ͱ� �ʿ��� ���� ���̸� �����ִ� ������ ������ ���� �����̴�.

�� Ŭ������ �������̽��� Ŭ���̾�Ʈ���� ����ϰ��� �ϴ� �ٸ� �������̽��� ��ȯ�Ѵ�.
����͸� �̿��� ȣȯ�� ���� ������ ���� �� �� ���� Ŭ�������� �����ؼ� �� �� �ִ�.

*/

#include <iostream>
using namespace std;

// �⺻ ��ü �ҽ�
class Object 
{
public:
	virtual void Draw() = 0;
};

// Object�� ��ӹ��� Circle �⺻ �ҽ�
class Circle : public Object
{
public:
	void Draw() { cout << "Draw Circle"; }
};




// ���� �ҽ��� ������ �ٸ������� ������ ��ü �ҽ�
class TextBox
{
public:
	void ViewText() { cout << "View Text"; }
};


// ���� ������ Text Box�� �������� �����, Draw�� �̸��� �����ش�.
class TextObject : public Object
{
private:
	TextBox* pObj;

public:
	TextObject() { pObj = new TextBox; }
	void Draw() { pObj->ViewText(); }

};


// Object�� ���� �˷��ִ� �Լ�
void DisplayObject(Object* pObj)
{
	if (pObj != 0) { pObj->Draw(); }
}

int main()
{
	TextObject tBox;
	DisplayObject(&tBox);

}