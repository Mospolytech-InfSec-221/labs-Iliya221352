#include <iostream>
#include <queue>
bool prime(int n) {
	bool is_235 = true;
	int i = 2;
	while (i * i <= n) {
		while (n % i == 0) {
			if (i != 2 and i != 3 and i != 5)
				is_235 = false;
			n /= i;
		}
		i++;
	}
	if (n != 2 and n != 3 and n != 5)
		is_235 = false;

	return is_235;
}
// сделано
void task_queue() {
	std::queue <int> q;
	int n;
	std::cout << "Введите число n: ";
	std::cin >> n;
	for (int i = 2; i < n; i++) {
		if (prime(i)) {
			q.push(i);
		}
	}
	for (int i = 0; i < q.size(); i++) {
		std::cout << q.front() << '\n';
		q.pop();
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	task_queue();
}