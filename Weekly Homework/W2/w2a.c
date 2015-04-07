#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int total_input;
            scanf("%d", &total_input);
            int i = 0, data_point[total_input * 2];
            while(total_input--) {
                scanf("%d %d", &data_point[i], &data_point[i + 1]);
                i += 2;
            }
            int max_area = 0, max_array_index = i; /*The value is right after the last element*/

            int data_pointer_left, data_pointer_right;
            for(data_pointer_left = 0; data_pointer_left < max_array_index; data_pointer_left += 2) {
                for(data_pointer_right = data_pointer_left + 2; data_pointer_right < max_array_index; data_pointer_right += 2) {
                    int temp_area = abs(data_point[data_pointer_left] - data_point[data_pointer_right]) * abs(data_point[data_pointer_left + 1] - data_point[data_pointer_right + 1]);
                    max_area = temp_area > max_area ? temp_area : max_area;
                }
            }
            printf("%d\n", max_area);
        }
    }

    return 0;
}