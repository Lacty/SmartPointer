
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

    // �R�s�[�s��
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
    ptr = make_shared<int>(10);  // make_shared���������m�ۂ������I�炵��
    cout << &ptr << endl;
    cout << *ptr << endl;

    shared_ptr<int> cpy;

    // �R�s�[��
    cpy = ptr;

    // �z�Q�ƁF���݂ɎQ�Ƃ���������
    // pHoge1->ptr = pHoge2;
    // pHoge2->ptr = pHoge1;
    // ���������[�N���������邱�Ƃ�����
  }


  //---------------------------------------------------
  // ���L���̗L��
  //---------------------------------------------------

  {
    unique_ptr<int> ptr;
    if (!ptr) { cout << "���L���������Ă��܂���" << endl; }

    ptr = make_unique<int>(10);
    if (ptr) { cout << "���L���������Ă��܂�" << endl; }
  }


  //---------------------------------------------------
  // �|�C���^�̔z��
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
