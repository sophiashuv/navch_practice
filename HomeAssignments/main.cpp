#include <math.h>
#include "01_multiplication_table.h"
#include "02_find_max_in_sequence.h"
#include "03_array_tasks.h"
#include "04_min_element_square_matrix.h"
#include "05_compare_triangle_areas.h"
#include "06_abs_sum.h"
#include "07_min_max.h"
#include "08_change_values.h"
#include "09_find_another.h"
#include "10_create_matrix.h"
#include "11_count_sum.h"

#include <iostream>
using namespace std;

int main() {
    int n;
    while (true) {
        cout << "\nENTER NUMBER OF TASK: ";
        cin >> n;
        switch (n) {
            case 1: {
                multiplication_by_seven();
                continue;
            }
            case 2: {
                find_max_in_sequence();
                continue;
            }
            case 3: {
                array_tasks();
                continue;
            }
            case 4: {
                min_element_square_matrix();
                continue;
            }
            case 5: {
                compare_areas();
                continue;
            }
            case 6: {
                abs_sum();
                continue;
            }
            case 7: {
                min_max();
                continue;
            }
            case 8: {
                change_values();
                continue;
            }
            case 9: {
                find_another();
                continue;
            }
            case 10: {
                create_matrix();
                continue;
            }
            case 11: {
                count_sum();
                continue;
            }
            default:
                break;
        }

        system("pause");
        return 0;
    }
}
