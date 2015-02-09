
#include <jni.h>
#include "moai-core/pch.h"
#include <moai-android/moaiext-jni.h>
#include <moai-admob-android/MOAIAdmobAndroid.h>

extern JavaVM* jvm;

//----------------------------------------------------------------//
/**	@name	bannerReady
	@text	Returns whether banner is ready to be shown.

	@out	boolean 
*/
int MOAIAdmobAndroid::_bannerReady ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );

	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID bannerLoaded = env->GetStaticMethodID ( admob, "bannerReady", "()Z" );
   		if ( bannerLoaded == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "bannerLoaded" );
		} else {

			bool bannerReady = ( bool ) env->CallStaticBooleanMethod ( admob, bannerLoaded );

			lua_pushboolean ( state, bannerReady );
			return 1;
		}
	}

	lua_pushboolean ( state, false );
	return 0;
}

//----------------------------------------------------------------//
/**	@name	interstitialReady
	@text	Returns whether interstitials is ready to be shown.

	@out	boolean 
*/
int MOAIAdmobAndroid::_interstitialReady ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );

	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID interstitialLoaded = env->GetStaticMethodID ( admob, "interstitialReady", "()Z" );
   		if ( interstitialLoaded == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "interstitialLoaded" );
		} else {

			bool interstitialReady = ( bool ) env->CallStaticBooleanMethod ( admob, interstitialLoaded );

			lua_pushboolean ( state, interstitialReady );
			return 1;
		}
	}

	lua_pushboolean ( state, false );
	return 0;
}

//----------------------------------------------------------------//
/**	@name	interstitialVisible
	@text	Returns whether interstitials is currently covering the screen.

	@out	boolean 
*/
int MOAIAdmobAndroid::_interstitialVisible ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );

	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID interstitialVisible = env->GetStaticMethodID ( admob, "interstitialVisible", "()Z" );
   		if ( interstitialVisible == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "interstitialVisible" );
		} else {

			bool interstitialShown = ( bool ) env->CallStaticBooleanMethod ( admob, interstitialVisible );

			lua_pushboolean ( state, interstitialShown );
			return 1;
		}
	}

	lua_pushboolean ( state, false );
	return 0;
}

//----------------------------------------------------------------//
/**	@name	bannerVisible
	@text	Returns whether a banner is currently covering the screen.

	@out	boolean 
*/
int MOAIAdmobAndroid::_bannerVisible ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );

	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID bannerVisible = env->GetStaticMethodID ( admob, "bannerVisible", "()Z" );
   		if ( bannerVisible == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "bannerVisible" );
		} else {

			bool bannerShown = ( bool ) env->CallStaticBooleanMethod ( admob, bannerVisible );

			lua_pushboolean ( state, bannerShown );
			return 1;
		}
	}

	lua_pushboolean ( state, false );
	return 0;
}

//----------------------------------------------------------------//
/**	@name	loadBanner
	@text	Starts loading a banner in the background.

	@out	nil
*/
int MOAIAdmobAndroid::_loadBanner ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );
    
	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID loadBanner = env->GetStaticMethodID ( admob, "loadBanner", "()V" );
   		if ( loadBanner == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "loadBanner" );
		} else {

			env->CallStaticVoidMethod ( admob, loadBanner );

			return 0;
		}
	}
    
    return 0;
}

//----------------------------------------------------------------//
/**	@name	loadInterstitial
	@text	Starts loading a interstitial in the background.

	@out	nil
*/
int MOAIAdmobAndroid::_loadInterstitial ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );
    
	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID loadInterstitial = env->GetStaticMethodID ( admob, "loadInterstitial", "()V" );
   		if ( loadInterstitial == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "loadInterstitial" );
		} else {

			env->CallStaticVoidMethod ( admob, loadInterstitial );

			return 0;
		}
	}
    
    return 0;
}

//----------------------------------------------------------------//
/**	@name	showBanner
	@text	Shows a loaded banner.

	@out	nil
*/
int MOAIAdmobAndroid::_showBanner ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );
    
	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID showBanner = env->GetStaticMethodID ( admob, "showBanner", "()V" );
   		if ( showBanner == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "showBanner" );
		} else {

			env->CallStaticVoidMethod ( admob, showBanner );

			return 0;
		}
	}
    
    return 0;
}

//----------------------------------------------------------------//
/**	@name	showInterstitial
	@text	Shows a loaded interstitial.

	@out	nil
*/
int MOAIAdmobAndroid::_showInterstitial ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );
    
	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID showInterstitial = env->GetStaticMethodID ( admob, "showInterstitial", "()V" );
   		if ( showInterstitial == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "showInterstitial" );
		} else {

			env->CallStaticVoidMethod ( admob, showInterstitial );

			return 0;
		}
	}
    
    return 0;
}

//----------------------------------------------------------------//
/**	@name	hideBanner
	@text	Hides loaded banner.

	@out	nil
*/
int MOAIAdmobAndroid::_hideBanner ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );
    
	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID hideBanner = env->GetStaticMethodID ( admob, "hideBanner", "()V" );
   		if ( hideBanner == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "hideBanner" );
		} else {

			env->CallStaticVoidMethod ( admob, hideBanner );

			return 0;
		}
	}
    
    return 0;
}

//----------------------------------------------------------------//
/**	@name	destroyAdview
	@text	Destroys adview, only useful with banners and when you exit your app.

	@out	nil
*/
int MOAIAdmobAndroid::_destroyAdview ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );
    
	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID destroyAdview = env->GetStaticMethodID ( admob, "destroyAdview", "()V" );
   		if ( destroyAdview == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "destroyAdview" );
		} else {

			env->CallStaticVoidMethod ( admob, destroyAdview );

			return 0;
		}
	}
    
    return 0;
}

//----------------------------------------------------------------//
/**	@name	requestTestAds
	@text	Call this before anything else and you will receive test ads.

	@out	nil
*/
int MOAIAdmobAndroid::_requestTestAds ( lua_State* L ) {
	JNI_GET_ENV ( jvm, env );
	MOAILuaState state ( L );
    
	jclass admob = env->FindClass ( "com/ziplinegames/moai/MoaiAdmob" );
    if ( admob == NULL ) {

		ZLLog::Print ( "MOAIAdmobAndroid: Unable to find java class %s", "com/ziplinegames/moai/MoaiAdmob" );
    } else {

    	jmethodID requestTestAds = env->GetStaticMethodID ( admob, "requestTestAds", "()V" );
   		if ( requestTestAds == NULL ) {

			ZLLog::Print ( "MOAIAdmobAndroid: Unable to find static java method %s", "requestTestAds" );
		} else {

			env->CallStaticVoidMethod ( admob, requestTestAds );

			return 0;
		}
	}
    
    return 0;
}



//================================================================//
// MOAIAdmobAndroid
//================================================================//

//----------------------------------------------------------------//
MOAIAdmobAndroid::MOAIAdmobAndroid () {
	RTTI_SINGLE ( MOAILuaObject )
}

//----------------------------------------------------------------//
MOAIAdmobAndroid::~MOAIAdmobAndroid () {
}

//----------------------------------------------------------------//
void MOAIAdmobAndroid::RegisterLuaClass ( MOAILuaState& state ) {
	luaL_Reg regTable [] = {
		{ "loadBanner",		        _loadBanner},
		{ "bannerReady",		    _bannerReady},
		{ "showBanner",			    _showBanner},
		{ "hideBanner",			    _hideBanner},
		{ "destroyAdview",		    _destroyAdview},
		{ "loadInterstitial",		_loadInterstitial},
		{ "interstitialReady",		_interstitialReady},
		{ "showInterstitial",		_showInterstitial},
		{ "interstitialVisible",	_interstitialVisible},
		{ "bannerVisible",	        _bannerVisible},
		{ "requestTestAds",	        _requestTestAds},
		{ NULL, NULL }
	};
    
    luaL_register ( state, 0, regTable );
}
