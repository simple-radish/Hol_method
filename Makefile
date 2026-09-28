all:
	g++ main.cpp func.cpp input.cpp solution.cpp -o a.out
run_1: all
	@echo "рабочая сборка"
	./a.out 3 2 0 input.txt
run_2: all
	./a.out 2000 6 1
run_3: all
	./a.out 100 6 3
run_4: all
	./a.out 2000 6 2
run_5: all
	./a.out 1000 6 4
test: all
	

	@echo "аргументы"
	@echo "нет аргументов"
	-./a.out
	@echo "мало аргументов"
	-./a.out 3 3
	@echo "слишком много аргументов"
	-./a.out 3 3 0 input.txt mnogo:0
	@echo "n не число"
	-./a.out abc 3 1
	@echo "n равно нулю"
	-./a.out 0 3 1
	@echo "n отрицательное"
	-./a.out -5 3 1
	@echo "m равно нулю"
	-./a.out 3 0 1
	@echo "k вне диапазона"
	-./a.out 3 3 7
	-./a.out 3 3 -1
	@echo "k ноль без файла"
	-./a.out 3 3 0
	@echo "k один с лишним файлом"
	-./a.out 3 3 1 input.txt

	@echo "файл"
	@echo "нет файла"
	-./a.out 3 3 0 nofile.txt
	@echo "мусор в файле"
	-./a.out 3 3 0 input_abc.txt
	@echo "мало чисел в файле"
	-./a.out 3 3 0 input_short.txt
	@echo "нормальный файл"
	-./a.out 3 3 0 input.txt

	@echo "формулы"
	-./a.out 4 4 1
	-./a.out 4 4 2
	-./a.out 4 4 3
	-./a.out 4 4 4

	@echo "печать m"
	@echo "m больше n, печатать всю"
	-./a.out 3 10 1
	@echo "m меньше n, только угол"
	-./a.out 10 3 1