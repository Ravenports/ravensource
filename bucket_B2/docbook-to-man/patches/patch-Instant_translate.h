--- Instant/translate.h.orig	1996-06-17 03:50:29 UTC
+++ Instant/translate.h
@@ -142,12 +142,14 @@ void	ProcessOneSpec(char *, Element_t *,
 void	TransElement(Element_t *, FILE *, Trans_t *);
 void	TranByAction(Element_t *, int, FILE *);
 void	TranTByAction(Element_t *, char *, FILE *);
+void    ExpandVariables (char *in, char *out, Element_t *e);
 
 /* prototypes for things defined in tranvar.c */
 void	ExpandSpecialVar(char *, Element_t *, FILE *, int);
 
 /* prototypes for things defined in tables.c */
 void	OSFtable(Element_t *, FILE *, char **, int);
+void    CALStable(Element_t *e, FILE *fp, char **av, int ac);
 
 /* ______________________________________________________________________ */
 
