
int static_array[10];
int y = 123;

void increment_y() {
    y++;
}

void do_smth() {}

int main() {
    do_smth();
    while (1) {
        increment_y();
    }
}
