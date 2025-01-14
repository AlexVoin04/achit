all:
	$(MAKE) -C myReadKey
	$(MAKE) -C myTerm
	$(MAKE) -C myBigChars
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C console
clean:
	$(MAKE) clean -C console
	$(MAKE) clean -C mySimpleComputer
	$(MAKE) clean -C myTerm
	$(MAKE) clean -C myBigChars
	$(MAKE) clean -C myReadKey
	$(MAKE) clean -C simpleassembler
	rm -rf result.o
as:
	$(MAKE) -C simpleassembler
run:  as
	$(MAKE) run -C simpleassembler 
