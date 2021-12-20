// 1. Singleton
/* 전역 변수를 사용하지 않고 객체를 오직 한 개만 갖도록 보장하며, 생성된 객체를 어디에서든지 참조할 수 있도록 하는 패턴

싱글턴 패턴을 이용하면, 하나의 인스턴스를 메모리에 등록해 여러 스레드가 동시에 해당 인스턴스를 공유하여 사용하게 할 수 있어
요청이 많은 곳에서 사용하면 효율을 높일 수 있다.

공통적인 특징은 Private Constructor, static method를 사용하는 점이다.

 하지만 싱글턴패턴은 Gof들도 권장하지 않는 생성패턴이며, 멀티쓰레드 사용시 충돌이 잃어나는등 의도와는 달리 득보다는 실이 많다고한다.
*/

//#include <iostream>
//using namespace std;
//
//class Singleton {
//private: // 복사 생성자, 생성자, 소멸자를 private에 선언하여, 복사, 상속을 못하게 막음
//	Singleton() {} // 생성자
//	Singleton(const Singleton& ref) {}
//	Singleton& operator=(const Singleton& ref) {}
//	~Singleton() {}
//
//public:
//	static Singleton& getInstance() // 정적변수인 static을 통한 정적 객체 한가지를 싱글톤패턴으로 만든다// getIncetance() 함수가 실행해야지 생성되는 늦은 초기화를 사용
//	{
//		static Singleton s;
//		return s;
//	}
//};




/* 2. Strategy // 전략 패턴

	실행 중에 알고리즘을 선택할 수 있게 하는 행위 소프트웨어 디자인 패턴이며, 특정 계열의 알고리즘들을 정의하고 각 알고리즘을 캡슐화하여
	해당 계열 안에서 상호 교체가 가능하게 만든다.

	특정 컨텍스트에서 알고리즘을 별도로 분리하는 설계 방법이다.
	즉 특정한 기능을 수행하는데에 있어 다양한 알고리즘을 적용 할 수 있게 별도로 분리하는 설계 방법.

	상속보다는 구성을 활용하여, 객체의 Composition을 통해서 미리 만들어놓고 사용자가 알아서
	dynamci 하게 갈아끼울 후 있도록 하는 것이다.
	또한 위임을 통해서 부모 class의 정의에서는 Composition을 통하여 만들어 놓은
	추상클라스 객체의 operation만을 사용하게 해둔다.

	코드의 재사용성을 높여주고 확장성을 높여주지만 복잡도는 함계 올라가고 성능에는 손해를 볼 수 있다.

*/


//#include <iostream>
//using namespace std;
//
//// 부모 클래스 Duck
//class Duck {
//public:
//	QuackBehavior* quackBehavior; // 구성 (composition)
//	FlyBehavior* flyBehavior; // 구성 (composition)
//
//	Duck() {}
//
//	void performQuack()
//	{
//		quackBehavior->quack(); // 위임 (delegation)
//	}
//	void performFly()
//	{
//		flyBehavior->fly(); // 위임 (delegation)
//	}
//
//	void setFlyBehavior(FlyBehavior* fb)
//	{
//		flyBehavior = fb;	// 객체 교체
//	}
//
//	void setQuackBehavior(QuackBehavior* qb)
//	{
//		quackBehavior = qb;
//	}
//};
//
//// Duck을 상속받는 청둥오리(MallardDuck) 클래스
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
//// Duck을 상속받는 오리인형(ModelDuck) 클래스
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
//// Quack Behavior 클래스
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
//// Fly Behavior 클래스
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
이미 제공되어 있는 것과 필요한 것의 차이를 없애주는 디자인 패턴중 구조 패턴이다.

한 클래스의 인터페이스를 클라이언트에서 사용하고자 하는 다른 인터페이스로 변환한다.
어댑터를 이용해 호환성 문제 때문에 같이 쓸 수 없는 클래스들을 연결해서 쓸 수 있다.

*/

#include <iostream>
using namespace std;

// 기본 객체 소스
class Object 
{
public:
	virtual void Draw() = 0;
};

// Object를 상속받은 Circle 기본 소스
class Circle : public Object
{
public:
	void Draw() { cout << "Draw Circle"; }
};




// 기존 소스에 쓰려고 다른곳에서 가져온 객체 소스
class TextBox
{
public:
	void ViewText() { cout << "View Text"; }
};


// 새로 가져온 Text Box를 쓰기위한 어댑터, Draw로 이름을 맞춰준다.
class TextObject : public Object
{
private:
	TextBox* pObj;

public:
	TextObject() { pObj = new TextBox; }
	void Draw() { pObj->ViewText(); }

};


// Object가 뭔지 알려주는 함수
void DisplayObject(Object* pObj)
{
	if (pObj != 0) { pObj->Draw(); }
}

int main()
{
	TextObject tBox;
	DisplayObject(&tBox);

}