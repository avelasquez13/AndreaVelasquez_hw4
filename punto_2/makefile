cuerda.gif : animacion.py valores.dat
	python animacion.py

valores.dat : cuerda.c
	gcc cuerda.c -lm
	./a.out > valores.dat

clean :
	rm a.out
	rm valores.dat
	