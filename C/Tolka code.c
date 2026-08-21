Fråaga 2: Tolka kod (4 p)
Vilken rad av siffror kommer följande program att skriva ut? Granska koden noga!
void modifyArray(int arr[], int size) {
for (int i = 0; i < 2 + size/2; i++) {
if (i <= 3) {
arr[i] += i;
} else {
arr[i] = 9;
}
}
}
int main() {
int numbers[] = {1, 2, 3, 4, 5, 6, 7};
int size = sizeof(numbers) / sizeof(numbers[0]);
modifyArray(numbers, size);
for (int i = 1; i < size; i++) {
printf("%d ", numbers[i]);
}
return 0;
}

// Den kommer att skriva ut : 3 5 7 9 6 7
