placas.pdf : grafica.py potencial.dat
	python grafica.py

potencial.dat : placas.c
	gcc placas.c -lm
	./a.out > potencial.dat

clean :
	rm a.out
	rm potencial.dat
