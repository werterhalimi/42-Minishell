Le projet minishell de l'école 42 consiste à développer un shell interactif, c'est-à-dire un programme permettant d'exécuter des commandes sur un ordinateur. Le shell doit être capable d'afficher un prompt en attente d'une nouvelle commande, de posséder un historique fonctionnel, de chercher et lancer les bons exécutables en se basant sur la variable d'environnement PATH, et de gérer les redirections et les pipes.

Le shell doit également implémenter les builtins cd, echo, pwd, export, unset, env et exit, ainsi que les gestionnaires de signaux ctrl-C, ctrl-D et ctrl-\ qui doivent fonctionner comme dans bash. En outre, le shell ne doit pas utiliser plus d'une variable globale, et doit gérer les variables d'environnement et le statut de sortie de la dernière pipeline exécutée.

Pour réaliser ce projet, les étudiants doivent utiliser les fonctions externes autorisées telles que readline, add_history, fork, wait, execve, etc. et la librairie Libft. Le code doit être soumis via un fichier Makefile contenant les règles NAME, all, clean, fclean et re, ainsi que les fichiers *.h et *.c correspondants.

En résumé, le projet minishell de l'école 42 est un défi de programmation qui permet aux étudiants de mettre en pratique leurs compétences en matière de gestion des entrées/sorties, de manipulation des processus et des signaux, et d'analyse syntaxique des commandes.

Signé, GPT-3.
