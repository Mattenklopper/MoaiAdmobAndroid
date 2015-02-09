#ifndef	MOAIAdmobAndroid_H
#define	MOAIAdmobAndroid_H

#include <moai-core/headers.h>


//================================================================//
// MOAIAdmobAndroid
//================================================================//
/**	@name	MOAIAdmobAndroid
	@text	Google AdMob for Android for lua for MOAI for developers.
*/
class MOAIAdmobAndroid :
    public MOAIGlobalClass < MOAIAdmobAndroid, MOAILuaObject > {
private:
	//----------------------------------------------------------------//
	static int 	_loadBanner             ( lua_State* L );
	static int 	_bannerReady            ( lua_State* L );
	static int 	_bannerVisible          ( lua_State* L );
	static int 	_showBanner             ( lua_State* L );
	static int  _hideBanner		        ( lua_State* L );
    static int  _destroyAdview          ( lua_State* L );
    static int  _loadInterstitial       ( lua_State* L );
    static int  _interstitialReady      ( lua_State* L );
    static int  _interstitialVisible    ( lua_State* L );
    static int  _showInterstitial       ( lua_State* L );
    static int  _requestTestAds         ( lua_State* L );
    
    
    
public:
	DECL_LUA_SINGLETON ( MOAIAdmobAndroid )

	//----------------------------------------------------------------//
				MOAIAdmobAndroid		();
				~MOAIAdmobAndroid		();
	void		RegisterLuaClass		( MOAILuaState& state );
};

#endif
