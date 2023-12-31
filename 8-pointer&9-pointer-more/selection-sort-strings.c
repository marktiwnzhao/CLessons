#include <stdio.h>
#include <string.h>
#define LEN 10

void SelectionSort(char *str[], int len);
void SwapWrong(char *left, char *right);
void Swap(char **left, char **right);
void PrintStrs(const char *str[], int len);

int main() {
    const char *names[LEN] = {//pointer array
            "Luo Dayou",
            "Cui Jian",
            "Dou Wei",
            "Zhang Chu",
            "He Yong",
            "Wan Qing",
            "WuTiaoRen",
            "Zuo Xiao",
            "Hu Mage",
            "Li Zhi"
    };

    PrintStrs(names, LEN);
    SelectionSort(names, LEN);
    PrintStrs(names, LEN);

    return 0;
}

void SelectionSort(char *str[], int len) {
    for (int i = 0; i < len; ++i) {
        const char *min = str[i];
        int min_index = i;

        for (int j = i + 1; j < len; j++) {
            if (strcmp(min, str[j]) > 0) {
                min = str[j];
                min_index = j;
            }
        }

        Swap(&str[i], &str[min_index]);
    }
}

void SwapWrong(char *left, char *right) {
    char tmp = *left;
    *left = *right;
    *right = tmp;
}

void Swap(char **left, char **right) {
    char *tmp = *left;
    *left = *right;
    *right = tmp;
}

void PrintStrs(const char *str[], int len) {
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%s\n", str[i]);
    }
    printf("\n");
}