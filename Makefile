.PHONY: all clean

all:
	@echo "Have to source ROOT."
	g++ -g -O2 -o 0vbb_phasespace.exe 0vbb_phasespace.C `root-config --cflags --libs` -lGeom
	@echo "DONE!"
clean:
	rm -r 0vbb_phasespace.exe
