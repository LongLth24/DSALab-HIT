# Tuần 8: Stack & Ứng Dụng — Bài tập

## 🎯 Mục tiêu tuần này
Cài đặt Stack bằng mảng và Linked List. Ứng dụng Stack trong bài toán thực tế.

---

### Bài 1: Cài đặt Stack ⭐⭐
Cài đặt Stack bằng mảng (array-based) và bằng Linked List. So sánh ưu nhược điểm.

#include <iostream>
using namespace std;
#define MAX 100
///stack linkedlist
struct Node{
    int data;
    Node* next;
};

Node* TaoNode(int x){
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
};

struct stack {
    Node* top = nullptr;
};

void CreateStack(stack &l){
    l.top = nullptr;
};

bool checklist(stack &l){
    return l.top == nullptr;
};
void pushlist(stack &l, int x){
    Node* p = TaoNode(x);
    p->next = l.top;
    l.top = p;
    cout << "[Linked List Stack] push: " << x << endl;
};

int poplist(stack &l){
    if(checklist(l)){
        cout << "Linked List Stack rỗng! Không thể pop.\n";
        return -1;
    }
    Node* p = l.top;
    int temp = p->data;
    l.top = l.top->next;
    delete p;
    return temp;
};

int peeklist(stack &l){
    if(checklist(l)) return -1;
    return l.top->data;
};

void clearlist(stack &l){
    while(!checklist(l))
        poplist(l);
};

void instack(stack &l) {
    if (checklist(l)) { cout << "[Danh sach rong]\n"; return; }
    cout << "HEAD -> ";
    Node *cur = l.top;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << " -> NULL\n";
}
///

///stack Array
struct ArrayStack{
  int top = -1;
  int arr[MAX];
};

bool None(ArrayStack &a){
    return a.top < 0;
};

bool Full(ArrayStack &a){
    return a.top >= (MAX-1);
}

void pushA(ArrayStack &a, int x){
  if(Full(a)){
        cout << "Array Stack đầy! Không thể push " << x << endl;
        return;
  }
  a.arr[++a.top] = x;
  cout << "[Array Stack] Đã push: " << x << endl;
};

int popA(ArrayStack &a){
  if(None(a)){
        cout << "Array Stack rỗng! Không thể pop.\n";
        return -1;
  }
  return a.arr[a.top--];
};

int peekA(ArrayStack &a){
    if(None(a)){
        cout << "Array Stack rỗng!\n";
        return -1;
    }
    return a.arr[a.top];
};

void inA(ArrayStack &a){
    if(None(a)){
        cout << "[Array Stack rỗng]" << endl;
        return;
    }
    cout << "TOP ->";
    for (int i = a.top; i >= 0; --i){
        cout << a.arr[i];
        if (i > 0 ) cout << " -> ";
    }
    cout << " -> BOTTOM" << endl;
}

void clearA(ArrayStack &a){
    a.top = -1;
    cout << "[Array Stack] Đã xóa hết!" << endl;
}
///

int main(){
    stack s1;
    //CreateStack(s1);
    pushlist(s1, 2);
    pushlist(s1, 74);
    pushlist(s1, 123);
    instack(s1);
    cout << "Phần tử trên cùng (peek): " << peeklist(s1) << endl;
    cout << "Đã pop: " << poplist(s1) << endl;
    clearlist(s1);
    instack(s1);
    
    cout << endl;
    
    ArrayStack s2;
    pushA(s2, 5);
    pushA(s2, 83);
    pushA(s2, 234);
    inA(s2);
    cout << "Phần tử trên cùng (peek): " << peekA(s2) << endl;
    cout << "Đã pop: " << popA(s2) << endl;
    clearA(s2);
    inA(s2);

    return 0;
}

### Bài 2: Kiểm tra ngoặc hợp lệ ⭐⭐
Kiểm tra chuỗi có đóng mở ngoặc `()`, `[]`, `{}` hợp lệ không. Xử lý cả chuỗi code thực tế.

### Bài 3: Chuyển đổi biểu thức ⭐⭐⭐
Chuyển biểu thức Infix → Postfix → Prefix. In từng bước.

### Bài 4: 🔥 Dự Án Mini — Máy Tính Biểu Thức ⭐⭐⭐
> **Cảm hứng:** [Pilha_Expressão_A — DanielSantDev/Projects-with-Cpp](https://github.com/DanielSantDev/Projects-with-Cpp)

Xây dựng máy tính tính biểu thức toán học bằng Stack:
```
=== 🧮 MÁY TÍNH BIỂU THỨC ===
Nhập biểu thức: (3 + 4) * 2 - 8 / 4

Bước 1 — Chuyển sang Postfix: 3 4 + 2 * 8 4 / -
Bước 2 — Tính toán:
  Push 3 → Stack: [3]
  Push 4 → Stack: [3, 4]
  '+' → Pop 4, Pop 3 → Push 7 → Stack: [7]
  Push 2 → Stack: [7, 2]
  '*' → Pop 2, Pop 7 → Push 14 → Stack: [14]
  ...

✅ Kết quả: (3 + 4) * 2 - 8 / 4 = 12
```
**Yêu cầu:** hỗ trợ +, -, *, /, ^, ngoặc đơn, số thập phân, hiển thị từng bước stack.

---
📁 Tham khảo: `Chuong3_DanhSachLienKet/Chuong3_DanhSachLienKet.cpp`
