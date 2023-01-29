#include <stdio.h>
#define MAX_PAGE_FRAMES 10
#define MAX_PAGE_REFERENCES 20
int page_frames[MAX_PAGE_FRAMES];
int page_reference_string[MAX_PAGE_REFERENCES] = {1, 2, 3, 4, 5, 6,  7, 8, 9, 10, 11, 12, 13, 14};
int page_faults = 0;
int find_page_fault(int page_reference) {
    int i;
    for (i = 0; i < MAX_PAGE_FRAMES; i++) {
        if (page_frames[i] == page_reference) {
            return 0;
        }
    }
    return 1;
}
int find_optimal(int current_index) {
    int i, j, max_distance = -1, optimal_index = -1;
    for (i = 0; i < MAX_PAGE_FRAMES; i++) {
        int distance = -1;
        for (j = current_index; j < MAX_PAGE_REFERENCES; j++) {
            if (page_frames[i] == page_reference_string[j]) {
                distance = j - current_index;
                break;
            }
        }
        if (distance > max_distance) {
            max_distance = distance;
            optimal_index = i;
        }
    }
    return optimal_index;
}
int main() {
    int i, j, current_page, next_page, optimal;
    for (i = 0; i < MAX_PAGE_FRAMES; i++) {
        page_frames[i] = -1;
    }
    for (i = 0; i < MAX_PAGE_REFERENCES; i++) {
        current_page = page_reference_string[i];
        if (find_page_fault(current_page)) {
            page_faults++;
            if (page_faults <= MAX_PAGE_FRAMES) {
                for (j = 0; j < MAX_PAGE_FRAMES; j++) {
                    if (page_frames[j] == -1) {
                        page_frames[j] = current_page;
                        break;
                    }
                }
            } else {
                optimal = find_optimal(i);
                page_frames[optimal] = current_page;
            }
        }
        printf("Page frames: ");
        for (j = 0; j < MAX_PAGE_FRAMES; j++) {
            printf("%d ", page_frames[j]);
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", page_faults);
    return 0;
}
