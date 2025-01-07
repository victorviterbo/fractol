import os
dev = "libft/"
a =['characters', 'conversions', 'lists', 'math', 'memory', 'miscs', 'printf', 'strings', 'write_read']
rendu = "../fractol_rendu/libft/"
#print("rm ../fractol_rendu/*")
#print("cp *.c *.h Makefile ../fractol_rendu/*")
os.system("rm -fr ../fractol_rendu/*")
os.system("cp *.c *.h Makefile ../fractol_rendu/")
os.system("cp -r minilibx* ../fractol_rendu/")
os.system("mkdir "+rendu)
os.system("cp libft/*.h libft/Makefile ../fractol_rendu/libft")
for f in a:
    #print("rm -rf "+rendu+f)
    #print("mkdir "+rendu+f)
    #print("cp "+dev+f+"/* "+rendu +f+"/")
    os.system("rm -rf "+rendu+f)
    os.system("mkdir "+rendu+f)
    os.system("cp "+dev+f+"/* "+rendu +f+"/")

