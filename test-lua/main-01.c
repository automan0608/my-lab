
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>

static void stackDump (lua_State *L) {
	int i;
	int top = lua_gettop(L);
	for (i = 1; i <= top; i++) {  /* repeat for each level */
		int t = lua_type(L, i);
		switch (t) {	

		case LUA_TSTRING:  /* strings */
			printf("'%s'", lua_tostring(L, i));
			break;

		case LUA_TBOOLEAN:  /* booleans */
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;

		case LUA_TNUMBER:  /* numbers */
			printf("%g", lua_tonumber(L, i));
			break;
	
		default:  /* other values */
			printf("%s", lua_typename(L, t));
			break;

		}
		printf("  ");	/* put a separator */
	}
	printf("\n");		/* end the listing */
}


int main()
{
	lua_State *L = luaL_newstate();
	
	lua_pushnumber(L, 5.5);
	lua_pushnumber(L, 5.101);

	char *s1 = "this if first string";
	lua_pushlstring(L, s1, strlen(s1));
	
	char *s2 = "this if second string";
	lua_pushlstring(L, s2, strlen(s2));

	stackDump(L);
}
