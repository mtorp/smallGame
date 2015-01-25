game_objects  = brick.o game_impl.o player.o position.o
build_game_objects = $(addprefix build/, $(game_objects))
gg = g++ -Wall -g -Iinclude/ -Isrc/ -std=c++11 
gg_compile = $(gg) -c
gg_test = $(gg)
libraries = lib/libgtest.a -lpthread 
src = src
build = build


VPATH = src/ include/ build/


test: test_main.o	
	echo "invoking linker"	
	$(gg_test) build/test_main.o build/test_file.o $(build_game_objects) -o test $(libraries)

test_main.o: test_file.o gtest/gtest.h
	$(gg_compile) test_main.cpp -o $(build)/test_main.o

test_file.o: $(game_objects)
	$(gg_compile) test_file.cpp -o $(build)/test_file.o

position.o: position.h
	$(gg_compile) $(src)/position.cpp -o $(build)/position.o	

player.o: player.h color.h
	$(gg_compile) $(src)/player.cpp -o $(build)/player.o

brick.o: color.h brick.h
	$(gg_compile) $(src)/brick.cpp -o $(build)/brick.o

game_impl.o: game_impl.h game.h position.o brick.o player.o 
	$(gg_compile) $(src)/game_impl.cpp -o $(build)/game_impl.o

clean:
	rm build/*.o


