#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define RIGHT 1
#define LEFT -1
 
int main()
{
    int total_cells, total_instructions;
    while(scanf("%d %d", &total_cells, &total_instructions) != EOF && total_cells) {
        int instruction[total_cells];
        for(int i = 0; i < total_cells; i++)
            scanf("%d", &instruction[i]);
        while(total_instructions--) {
            int position, direction;
            scanf("%d %d", &position, &direction);
 
            //printf("%d %d\n", position, direction);
            //for(int i = 0; i < total_cells; i++)
            //printf("%d ", instruction[i]);
            //printf("\n");
 
            int cycle = 1, record[total_cells * 2];
            memset(record, 0, sizeof(record));
            while(position >= 0 && position < total_cells) {
                //cycle
                if(direction > 0) {
                    if(record[position] != 0) {
                        cycle = cycle - record[position];
                        //printf("break\n");
                        break;
                    }
                    record[position] = cycle++;
                } else {
                    if(record[abs(position) + total_cells] != 0) {
                        cycle = cycle - record[abs(position) + total_cells];
                        //printf("break\n");
                        break;
                    }
                    record[abs(position) + total_cells] = cycle++;
                }
 
                //determine next position
                if(instruction[position] > 0) {
                    //change position
                    //printf(">0\n");
                    if(direction == LEFT)
                        position = position - instruction[position];
                    else
                        position = position + instruction[position];
                } else if(instruction[position] < 0) {
                    //change direction
                    //printf("<0\n");
                    if(direction == LEFT)
                        direction = RIGHT;
                    else
                        direction = LEFT;
 
                    //change position
                    if(direction == LEFT)
                        position = position - abs(instruction[position]);
                    else
                        position = position + abs(instruction[position]);
                }
                //printf("%d\n", position);
            }
            //printf("end = %d\n", position);
            if(position >= 0 && position < total_cells)
                printf("Cycle %d\n", cycle);
            else {
                if(position >= total_cells)
                    printf("Forward\n");
                else
                    printf("Backward\n");
            }
        }
    }
 
    return 0;
}