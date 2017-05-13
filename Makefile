# example: make run a=1

_glib = `pkg-config --cflags --libs glib-2.0`
_gsl = `pkg-config --cflags --libs gsl`

compile_and_run = gcc -Wall -o $(1).o $(1).c $(_glib) $(_gsl) -lm && ./$(1).o && rm $(1).o

compile_and_run_mp = gcc -Wall -o $(1).o $(1).c $(_glib) $(_gsl) -lm -fopenmp && ./$(1).o && rm $(1).o

run:
	$(call compile_and_run,$(a))

run_mp:
	$(call compile_and_run_mp,$(a))
