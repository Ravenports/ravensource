#ifndef _RPC_SCAN_H_
#define _RPC_SCAN_H_

/*
 * kinds of tokens
 */
enum tok_kind {
	TOK_IDENT,
	TOK_CHARCONST,
	TOK_STRCONST,
	TOK_LPAREN,
	TOK_RPAREN,
	TOK_LBRACE,
	TOK_RBRACE,
	TOK_LBRACKET,
	TOK_RBRACKET,
	TOK_LANGLE,
	TOK_RANGLE,
	TOK_STAR,
	TOK_COMMA,
	TOK_EQUAL,
	TOK_COLON,
	TOK_SEMICOLON,
	TOK_CONST,
	TOK_STRUCT,
	TOK_UNION,
	TOK_SWITCH,
	TOK_CASE,
	TOK_DEFAULT,
	TOK_ENUM,
	TOK_TYPEDEF,
	TOK_INT,
	TOK_SHORT,
	TOK_LONG,
	TOK_HYPER,
	TOK_UNSIGNED,
	TOK_FLOAT,
	TOK_DOUBLE,
	TOK_QUAD,
	TOK_OPAQUE,
	TOK_CHAR,
	TOK_STRING,
	TOK_BOOL,
	TOK_VOID,
	TOK_PROGRAM,
	TOK_VERSION,
	TOK_EOF
};
typedef enum tok_kind tok_kind;

/*
 * a token
 */
struct token {
	tok_kind kind;
	const char *str;
};
typedef struct token token;


/*
 * routine interface
 */
void	scan(tok_kind, token *);
void	scan2(tok_kind, tok_kind, token *);
void	scan3(tok_kind, tok_kind, tok_kind, token *);
void	scan_num(token *);
void	peek(token *);
int	peekscan(tok_kind, token *);
void	get_token(token *);

#endif /* _RPC_SCAN_H_ */
