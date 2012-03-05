lockcddoor: lockcddoor.c
	cc -o lockcddoor lockcddoor.c

clean:
	rm -f lockcddoor cd-lock cd-unlock

links:
	ln -s lockcddoor cd-lock
	ln -s lockcddoor cd-unlock
