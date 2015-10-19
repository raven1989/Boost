bind:
	@g++ Bind.cpp

split_regex:
	@g++ -lboost_regex Split_regex.cpp
	@otool -L a.out
	install_name_tool -change libboost_regex.dylib /opt/boost_1_57_0/stage/lib/libboost_regex.dylib a.out
	@otool -L a.out
	@echo "SUCCEEDED!"

clean:
	rm -rf a.out
