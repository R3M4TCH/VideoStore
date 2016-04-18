test: Video.o BD.o DVD.o VHS.o Customer.o Store.o StoreMaker.o
	g++ Video.o BD.o DVD.o VHS.o Customer.o Store.o StoreMaker.o -o test

Video.o: Video.h Video.cpp
	g++ -c Video.cpp

BD.o: BD.h BD.cpp Video.h
	g++ -c BD.cpp

DVD.o: DVD.h DVD.cpp Video.h
	g++ -c DVD.cpp

VHS.o: VHS.h VHS.cpp Video.h
	g++ -c VHS.cpp

Customer.o: Customer.h Customer.cpp Video.h BD.h VHS.h DVD.h
	g++ -c Customer.cpp

Store.o: Store.h Store.cpp Customer.h Video.h BD.h VHS.h DVD.h
	g++ -c Store.cpp

StoreMaker.o: StoreMaker.cpp Store.h Customer.h Video.h BD.h VHS.h DVD.h
	g++ -c StoreMaker.cpp