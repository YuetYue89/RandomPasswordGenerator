all: getrandom.so 

getrandom.so: getrandom.c
	gcc -shared -fPIC getrandom.c -o getrandom.so 

run:
	@ echo Running passgen.py 5 times:
	@ for i in a b c d e; do \
		python3 ./passgen.py ;done
	@ echo Running passgen.py 5 times with getrandom preloaded
	@ export LD_PRELOAD="$$PWD/getrandom.so" ; for i in a b c d e; do \
	       	python3 ./passgen.py ;done

clean:
	rm -f getrandom.so

test:	all
	@ echo "Running passgen.py 5 times without our replacement of getrandom()"
	@ unset LD_PRELOAD
	@ for i in a b c d e; do \
		python3 ./passgen.py ; done
	@ echo "Running passgen.py 5 times with our replacement of getrandom()"
	@ export LD_PRELOAD=$$PWD/getrandom.so ; for i in a b c d e; do \
		python3 ./passgen.py ; done
	@ unset LD_PRELOAD
