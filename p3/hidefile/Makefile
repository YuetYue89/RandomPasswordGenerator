all:	hidefile.so

hidefile.so:	hidefile.c
	gcc -shared -fPIC hidefile.c -o hidefile.so 

test:	all
	@ echo creating "secret-1.txt"; echo "this file is hidden" >secret-1.txt
	@ echo creating "secret-2.txt"; echo "this file is also hidden" >secret-2.txt
	@ echo creating "secret-3.txt"; echo "this file is also hidden" >secret-3.txt
	@ echo Three files: ;ls -l
	@ echo;echo "hiding secret-1.txt"
	export HIDDEN=secret-1.txt LD_PRELOAD="$$PWD"/hidefile.so; ls -l
	@ echo; echo "hiding secret-2.txt"
	export HIDDEN=secret-2.txt LD_PRELOAD="$$PWD"/hidefile.so; ls -l
	@ echo; echo "hiding secret-1.txt and secret-2.txt"
	export HIDDEN=secret-1.txt:secret-2.txt LD_PRELOAD="$$PWD"/hidefile.so; ls -l
	@ echo;echo "hiding nothing"
	unset HIDDEN
	LD_PRELOAD="$$PWD"/hidefile.so; ls -l

clean:
	rm -f hidefile.so secret-1.txt secret-2.txt secret-3.txt

