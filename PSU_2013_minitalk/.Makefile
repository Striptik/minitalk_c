all:
	cd my/; make
	cd server_dir/; make
	cd client_dir/; make

clean:
	cd my/; make clean
	cd server_dir/; make clean
	cd client_dir/; make clean

fclean:
	cd my/; make fclean
	cd server_dir/; make fclean
	cd client_dir/; make fclean

re: fclean all

.PHONY: all clean fclean re
