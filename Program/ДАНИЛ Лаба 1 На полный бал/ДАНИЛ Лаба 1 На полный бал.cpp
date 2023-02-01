/*6. Сделать реализацию отсортирванного массива sorted_array
с фиксированной capacity (не растет) на шаблонах. При добавлении
элемента массив остается отсортированным. Для реализации с Point
использовать перегрузку оператора меньше.
sorted_array(size_t capacity)
push (бросает исключения при превышении capacity)
size
operator[]
at (бросает исключения)
erase(size_t i) (бросает исключения)
*/

#include "Header.h"

int main() {

    Array <int> m;
    Array <point> M;

    /*--------------INT-----------------

    m.set();

    m.size();

    m.push();


    int index = 0;

    cout << "The index of the number we want to display: ";
    cin >> index;

    cout << "Element: " << m.at(index) << endl;


    cout << "\nThe index of the number we want to remove: ";
    cin >> index;

    m.erase(index);*/

    /*-------------POINT-----------*/

    M.set();

    cout<<"\nArray: ";
    M.get();

    M.size();

    M.push();

    int index = 0;

    cout<<"index withdraw: ";
    cin>>index;

    cout<<"Element: "<<M.at(index)<<endl;


    cout<<"\nindex del: ";
    cin>>index;

    M.erase(index);

}
