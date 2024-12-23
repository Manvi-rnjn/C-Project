#include <stdio.h>
#include <string.h>
#define m 10

struct r {
    int id;
    char nm[20];
    int s[m];
} b[m];

int c = 0;

void addb() {
    printf("add bus id: ");
    scanf("%d", &b[c].id);
    printf("add bus name: ");
    scanf("%s", b[c].nm);
    for (int i = 0; i < m; i++) b[c].s[i] = 0;
    c++;
    printf("bus added\n");
}

void remb() {
    int id, idx = -1;
    printf("enter bus id to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < c; i++) {
        if (b[i].id == id) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("bus not found\n");
        return;
    }
    for (int i = idx; i < c - 1; i++) {
        b[i] = b[i + 1];
    }
    c--;
    printf("bus removed\n");
}

void dispb() {
    for (int i = 0; i < c; i++) {
        printf("id: %d name: %s seats: ", b[i].id, b[i].nm);
        for (int j = 0; j < m; j++) printf("%d ", b[i].s[j]);
        printf("\n");
    }
}

void res() {
    int id, st;
    printf("enter bus id: ");
    scanf("%d", &id);
    for (int i = 0; i < c; i++) {
        if (b[i].id == id) {
            printf("enter seat (1-%d): ", m);
            scanf("%d", &st);
            if (st < 1 || st > m || b[i].s[st - 1] == 1) {
                printf("seat unavailable\n");
                return;
            }
            b[i].s[st - 1] = 1;
            printf("seat reserved\n");
            return;
        }
    }
    printf("bus not found\n");
}

void canc() {
    int id, st;
    printf("enter bus id: ");
    scanf("%d", &id);
    for (int i = 0; i < c; i++) {
        if (b[i].id == id) {
            printf("enter seat (1-%d): ", m);
            scanf("%d", &st);
            if (st < 1 || st > m || b[i].s[st - 1] == 0) {
                printf("seat not reserved\n");
                return;
            }
            b[i].s[st - 1] = 0;
            printf("reservation cancelled\n");
            return;
        }
    }
    printf("bus not found\n");
}

void searchb() {
    int id;
    printf("enter bus id to search: ");
    scanf("%d", &id);
    for (int i = 0; i < c; i++) {
        if (b[i].id == id) {
            printf("id: %d name: %s seats: ", b[i].id, b[i].nm);
            for (int j = 0; j < m; j++) printf("%d ", b[i].s[j]);
            printf("\n");
            return;
        }
    }
    printf("bus not found\n");
}

void dispavl() {
    for (int i = 0; i < c; i++) {
        printf("bus id: %d name: %s available seats: ", b[i].id, b[i].nm);
        for (int j = 0; j < m; j++) {
            if (b[i].s[j] == 0) printf("%d ", j + 1);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("1. add bus\n2. remove bus\n3. display buses\n4. reserve seat\n5. cancel reservation\n6. search bus\n7. display available seats\n8. exit\n");
        printf("choice: ");
        scanf("%d", &ch);
        if (ch == 1) addb();
        else if (ch == 2) remb();
        else if (ch == 3) dispb();
        else if (ch == 4) res();
        else if (ch == 5) canc();
        else if (ch == 6) searchb();
        else if (ch == 7) dispavl();
        else if (ch == 8) break;
        else printf("invalid\n");
    }
    return 0;
}
