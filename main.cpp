
#include <iostream>
#include <memory>

using namespace std;


int main() {
  //---------------------------------------------------
  // unique_ptr
  //---------------------------------------------------

  {
    unique_ptr<int> ptr(new int(10));
    cout << &ptr << endl;
    cout << *ptr << endl;
  }

  {
    unique_ptr<int> ptr;
    ptr = make_unique<int>(10);
    cout << &ptr << endl;
    cout << *ptr << endl;

    unique_ptr<int> cpy;

    // コピー不可
    // cpy = ptr;   // err
  }

  //---------------------------------------------------
  // shared_ptr
  //---------------------------------------------------

  {
    shared_ptr<int> ptr(new int(10));
    cout << &ptr << endl;
    cout << *ptr << endl;
  }

  {
    shared_ptr<int> ptr;
    ptr = make_shared<int>(10);  // make_sharedがメモリ確保が効率的らしい
    cout << &ptr << endl;
    cout << *ptr << endl;

    shared_ptr<int> cpy;

    // コピー可
    cpy = ptr;

    // 循環参照：相互に参照し合うこと
    // pHoge1->ptr = pHoge2;
    // pHoge2->ptr = pHoge1;
    // メモリリークが発生することもある
  }


  //---------------------------------------------------
  // 所有権の有無
  //---------------------------------------------------

  {
    unique_ptr<int> ptr;
    if (!ptr) { cout << "所有権を持っていません" << endl; }

    ptr = make_unique<int>(10);
    if (ptr) { cout << "所有権を持っています" << endl; }
  }


  //---------------------------------------------------
  // ポインタの配列
  //---------------------------------------------------

  {
    unique_ptr<int[]> ptr(new int[2]);
    ptr[0] = 10;
    ptr[1] = 10;

    for (int i = 0; i < 2; ++i) {
      cout << ptr[i] << endl;
    }
  }
}
