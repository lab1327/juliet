#include <stdio.h>

void lru(int string[20], int n, int size) {
    // Creating array for block storage
    int frames[n];
    // Initializing each block with -1
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }

    // Index to insert element
    int index = -1;

    // Counters
    int page_miss = 0;
    int page_hits = 0;

    // Traversing each symbol in fifo
    for (int i = 0; i < size; i++) {
        int symbol = string[i];
        int flag = 0;

        // Check if symbol is already in frames
        for (int j = 0; j < n; j++) {
            if (symbol == frames[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            printf("\nSymbol: %d  Frame: ", symbol);
            for (int j = 0; j < n; j++) {
                printf("%d ", frames[j]);
            }
            page_hits += 1;
        } else {
            // Check if there is an empty frame
            int empty_frame = -1;
            for (int j = 0; j < n; j++) {
                if (frames[j] == -1) {
                    empty_frame = j;
                    break;
                }
            }

            if (empty_frame != -1) {
                // Use the empty frame
                frames[empty_frame] = symbol;
                page_miss += 1;
                printf("\nSymbol: %d  Frame: ", symbol);
                for (int j = 0; j < n; j++) {
                    printf("%d ", frames[j]);
                }
            } else {
                // Frames are full, apply LRU
                int lru_index = -1;
                int least_recently_used = size;
                
                for (int j = 0; j < n; j++) {
                    int k;
                    for (k = i - 1; k >= 0; k--) {
                        if (string[k] == frames[j]) {
                            if (k < least_recently_used) {
                                least_recently_used = k;
                                lru_index = j;
                            }
                            break;
                        }
                    }
                }
                
                // Now assign symbol in LRU position
                frames[lru_index] = symbol;
                page_miss += 1;
                printf("\nSymbol: %d  Frame: ", symbol);
                for (int j = 0; j < n; j++) {
                    printf("%d ", frames[j]);
                }
            }
        }
    }
    printf("\nPage hits: %d", page_hits);
    printf("\nPage misses: %d", page_miss);
}

// Main function
int main(void) {
    int string[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int no_frames = 4;
    int size = sizeof(string) / sizeof(int);
    lru(string, no_frames, size);
    return 0;
}
