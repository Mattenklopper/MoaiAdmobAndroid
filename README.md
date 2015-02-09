# MoaiAdmobAndroid
A plugin for MOAI that lets you use Google admob in your app.

This plugin allows you to use interstitials and 1 pre-specified banner ad in your app. It is currently not possible to move the location of the banner ad through lua.

INSTALLATION:
To use Google Admob with the least performance impact it is required to make some changes to the default MOAI Android host also to maintain compatibility with MOAIKeyboardAndroid.
We'll be adding the banners as a window ontop of MOAI as this makes a big difference in performance. 

Note: If you're only using interstitials these changes may not be needed but I have not tested this.

1. Import google play services in your app. This will allow you to import the play services package in Moai.java.
http://developer.android.com/google/play-services/setup.html
Follow the steps here, I've used the "Something else" option for 1.5 stable. I am not checking if the user has the latest google play services installed as I've been told it is not required for ads to properly function.

2. Setup android manifest xml.
https://developers.google.com/mobile-ads-sdk/docs/admob/android/quick-start
Scroll down to the manifest changes. We will be setting add unit ids etc in our java file.


3. Update Android host source files so we can display ads.
Add MoaiAdmob.java to your project in the same folder as Moai.java resides.

Moai.java
Add MoaiAdmob to the sExternalClasses array.
(You could try building your app now, if an error occurs you most likely did something wrong at step 1 or 2 or you didn't place MoaiAdmob.java in the correct folder.)

LinearLayoutIMETrap.java
We will be switching from a LinearLayout to relative layout so we have to import the RelativeLayout files.
```java
import android.widget.RelativeLayout;
```

Change the class LinearLayoutIMETrap extends from LinearLayout to RelativeLayout.
```java
public class LinearLayoutIMETrap extends RelativeLayout {
```

Update MOAIKeyboard to reflect the RelativeLayout changes. MOAI uses a hidden TextInput to capture keyboard input, we have to update it so it's still hidden to keep the keyboard working.
There's a couple of lines we have to change, below is what they should end up like. Everything you need to change is in the onCreate method.
```java
import android.widget.RelativeLayout;

mContainer.setLayoutParams ( new RelativeLayout.LayoutParams ( RelativeLayout.LayoutParams.FILL_PARENT, RelativeLayout.LayoutParams.FILL_PARENT ));
//mContainer.setOrientation ( LinearLayout.VERTICAL );


RelativeLayout.LayoutParams paramsKeyInTextView = new RelativeLayout.LayoutParams ( 1,1 );

// re-set the Margins so that the field is hidden.
paramsKeyInTextView.setMargins ( -64, 0, 0, 0 );
```

Confiure your ad unit id's and the banner location in MoaiAdmob.java.

Open MoaiAdmob.java and update the following variables to reflect your own ad unit id's. You can create ads on the google admob website.
bannerUnitId = "yourid"
interstitialUnitId = "yourid"

Change the size and placement of your banner.
bannerSize = AdSize.BANNER; For other sizes look at https://developers.google.com/mobile-ads-sdk/docs/admob/android/banner
bannerGravity = GRAVITY.TOP; For other gravities look at http://developer.android.com/reference/android/view/Gravity.html

And you're done!

USAGE:
After setting up the java side you can control the ads from lua.
List of functions available:

```lua
--Calling this before any other functions and you will receive test ads. 
--Do this while testing to prevent accidental clicks which can apparently result in account suspension.
MOAIAdmob.requestTestAds()

--Start loading a banner ad. On the google admob management page you can specify whether banners should auto refresh or not.
--There's no harm in calling this while a banner is still loading, if a banner is still loading this will do nothing instead.
MOAIAdmob.loadBanner()

--Boolean whether your banner is ready or not. If a banner is still loading this will return false. 
--Since loadBanner does not cause another banner to load if it's still actually loading a banner there's no harm in continously checking between your gamestates this and attempting to load a banner if false.
MOAIAdmob.bannerReady()

--Makes the banner visible and unpauses it. On first call this will insert the window.
MOAIAdmob.showBanner()

--Boolean whether the banner is currently visible.
MOAIAdmob.bannerVisible()

--Hides banner and pauses it.
MOAIAdmob.hideBanner()

--If you're using banners call this when exiting your app to properly get rid of the banner adview without a window leaking.
MOAIAdmob.destroyAdview()

--Start loading an interstitial. Operates the same as loadBanner
MOAIAdmob.loadInterstitial()

--Same as bannerReady
MOAIAdmob.interstitialReady()

--Same as banner. You can not close an interstitial, it has to be closed by the user.
MOAIAdmob.showInterstitial()

--This returns true as long as the interstitial is on screen. If a user presses back button or closes the interstitial this will return false. 
--I use this to try and prevent accidental clicks while changing gamestates.
MOAIAdmob.interstitialVisible()
```
