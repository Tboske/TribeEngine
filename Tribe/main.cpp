#include "TribePCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Tribe.h"

// resolves a linker error with sdl macro decl
#undef main
int main(int, char*[]) {
	Tribe engine;
	engine.Run();
    return 0;
}
