game_objects  = brick.o game_impl.o player.o position.o naive_winner_strategy.o
build_game_objects = $(addprefix build/, $(game_objects))
gg = g++ -Wall -g -Iinclude/ -Isrc/ -std=c++11 
gg_compile = $(gg) -c
test_objects = test_main.o test_file.o
build_test_objects = $(addprefix build/, $(test_objects))
libraries = lib/libgtest.a -lpthread 
src = src
build = build


VPATH = src/ include/ build/


test: $(game_objects) $(test_objects)	
	echo "invoking linker"	
	$(gg) $(build_test_objects) $(build_game_objects) -o test $(libraries)

test_main.o: gtest/gtest.h test_main.cpp build_dir
	$(gg_compile) test_main.cpp -o $(build)/test_main.o

test_file.o: gtest/gtest.h game_impl.h test_file.cpp build_dir
	$(gg_compile) test_file.cpp -o $(build)/test_file.o

position.o: position.h position.cpp build_dir
	$(gg_compile) $(src)/position.cpp -o $(build)/position.o	

player.o: player.h color.h player.cpp build_dir
	$(gg_compile) $(src)/player.cpp -o $(build)/player.o

brick.o: color.h brick.h brick.cpp build_dir
	$(gg_compile) $(src)/brick.cpp -o $(build)/brick.o

game_impl.o: game_impl.h game.h game_impl.cpp build_dir 
	$(gg_compile) $(src)/game_impl.cpp -o $(build)/game_impl.o

build_dir:
	mkdir build

naive_winner_strategy.o: winner_strategy.h naive_winner_strategy.h naive_winner_strategy.cpp
	$(gg_compile) $(src)/naive_winner_strategy.cpp -o $(build)/naive_winner_strategy.o
clean:
	rm build/*.o	
	rm test


