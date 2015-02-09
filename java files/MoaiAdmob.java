package com.ziplinegames.moai;
import com.ziplinegames.moai.*;

import android.app.Activity;
import com.google.android.gms.ads.*;

import android.view.*;
import java.lang.Runnable;
import java.lang.String;
import android.provider.*;
import java.security.NoSuchAlgorithmException;
import java.security.MessageDigest;

public class MoaiAdmob {
    private static AdView adView;
    private static InterstitialAd interstitialAd;
    private static AdRequest.Builder adRequestBuilder = null;
    private static Activity activity = null;
    private static WindowManager windowManager = null;    
    private static String bannerUnitId = "YOURUNITID"; //Your ad-id found on the google admob pages.
    private static String interstitialUnitId = "YOURUNITID"; //Your ad-id found on the google admob pages.
    private static AdSize bannerSize = AdSize.BANNER; //Banner type
    private static int bannerGravity = Gravity.TOP; //Banner location
    private static boolean firstLoadBanner;
    private static boolean bannerLoaded;
    private static boolean bannerLoading;
    private static boolean interstitialLoaded;
    private static boolean interstitialShown;
    private static boolean interstitialLoading;
    
    public static void onCreate(Activity mactivity) {
        MoaiLog.i ( "onCreate MoaiAdmob" );  
        activity = mactivity;
        firstLoadBanner = true;
        bannerLoaded = false;
        bannerLoading = false;
        interstitialLoaded = false;
        interstitialLoading = false;        
        interstitialShown = false;
        adView = null;
        interstitialAd = null;
        
        windowManager = activity.getWindowManager();
        
        adRequestBuilder = new AdRequest.Builder();
        adRequestBuilder.addTestDevice(AdRequest.DEVICE_ID_EMULATOR);
    }
    
    public static void loadBanner() {
        //MoaiLog.i ( "Loading ad" );
        if (!bannerLoading) {
            bannerLoaded = false;
            bannerLoading = true;
            if (adView == null) {
                adView = new AdView(activity);
                adView.setAdSize(bannerSize); 
                adView.setAdUnitId(bannerUnitId);
                adView.setVisibility(8);
                adView.setAdListener(new AdListener() {
                        public void onAdLoaded() {
                            if (firstLoadBanner) {
                                    WindowManager.LayoutParams windowParams = new WindowManager.LayoutParams();
                                    windowParams.gravity = bannerGravity;
                                    windowParams.x = 0;
                                    windowParams.y = 0;
                                    windowParams.height = WindowManager.LayoutParams.WRAP_CONTENT;
                                    windowParams.width = WindowManager.LayoutParams.WRAP_CONTENT;
                                    windowParams.flags = WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | WindowManager.LayoutParams.FLAG_FULLSCREEN 
                                        | WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL | WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN
                                        | WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS | WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED;
                                    windowParams.format = -1;
                                    windowParams.windowAnimations = 0;

                                    windowManager.addView(adView, windowParams);
                                    firstLoadBanner = false;
                                    adView.pause();
                            }
                            bannerLoaded = true;
                            bannerLoading = false;
                            //MoaiLog.i ( "Ad finished loading" );
                        }
                        
                         public void onAdFailedToLoad(int errorCode) {
                            bannerLoading = false;
                            MoaiLog.i ( "banner ad failed to load: error " + errorCode );                            
                        }                       
                });
            } 
            activity.runOnUiThread(new Runnable(){
                 public void run() {
                    adView.loadAd(adRequestBuilder.build());
                 }
            });
        }
    }
    
    public static void showBanner() {
        //MoaiLog.i ( "showing adg AdView" );
        activity.runOnUiThread(new Runnable(){
            public void run() {
                if (bannerLoaded) {
                    adView.resume(); 
                    adView.setVisibility(0);
                }
             }
        });               
    }
    
    public static void hideBanner() {
        //MoaiLog.i ( "Hiding ad AdView" );
        activity.runOnUiThread(new Runnable(){
             public void run() {
                adView.setVisibility(8);
                adView.pause(); 
             }
        });
    }
    
    public static boolean bannerVisible() {
        if (adView != null) {
            if (adView.getVisibility() == 0) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
    
    public static void loadInterstitial() {
        //MoaiLog.i ( "Loading interstital" );
        if (!interstitialLoading) {
            interstitialLoading = true;
            interstitialLoaded = false;
            
            if (interstitialAd == null) {
                interstitialAd = new InterstitialAd(activity);
                interstitialAd.setAdUnitId(interstitialUnitId); 
                interstitialAd.setAdListener(new AdListener() {
                        public void onAdLoaded() {
                            interstitialLoaded = true;
                            interstitialLoading = false;
                            //MoaiLog.i ( "interstitial finished loading" );
                        }
                        
                        public void onAdClosed() {
                            //MoaiLog.i ( "interstitial ad has been closed" );
                            interstitialShown = false;
                            interstitialLoaded = false;
                        }

                        public void onAdFailedToLoad(int errorCode) {
                            interstitialLoading = false;
                            MoaiLog.i ( "interstitial ad failed to load: error " + errorCode );                            
                        }
                });            
            }
        
            activity.runOnUiThread(new Runnable(){
                 public void run() {
                    interstitialAd.loadAd(adRequestBuilder.build());
                 }
            });
        }
    }
    
    public static void showInterstitial() {
        //MoaiLog.i ( "showing interstitial" );
        
        activity.runOnUiThread(new Runnable(){
            public void run() {
                if (interstitialLoaded) {
                    interstitialAd.show();
                    interstitialShown = true;
                }
            }
        });
    }
    
    public static boolean interstitialVisible() {
        return interstitialShown;
    }
    
    public static void destroyAdview() {
        if (adView != null && !firstLoadBanner) {
            windowManager.removeView(adView);
        }
    }
  
    public static void onPause() {
        if (adView != null) {
            if (adView.getVisibility() == 0) {
                //MoaiLog.i ( "Pausing AdView" );
                adView.pause();
            }        
        }
    }
    
    public static void onResume() {
        if (adView != null) {
            if (adView.getVisibility() == 0) {
                //MoaiLog.i ( "Resuming AdView" );
                adView.resume();
            }
        }
    }
    
    public static void onDestroy() { 
        if (adView != null) {
            //MoaiLog.i ( "Destroying AdView" );
            adView.destroy();
        }
    }
    
    public static boolean bannerReady() {
        return bannerLoaded;
    }
    
    public static boolean interstitialReady() {
        return interstitialLoaded;
    }

    public static void requestTestAds() {
        String deviceId = md5(Settings.Secure.getString(activity.getContentResolver(), Settings.Secure.ANDROID_ID)).toUpperCase();
        adRequestBuilder.addTestDevice(deviceId);
    }
    
    // http://stackoverflow.com/questions/4524752/how-can-i-get-device-id-for-admob/18114634#18114634 easy way to get test ads for every device
    private static final String md5(final String s) {
        try {
            // Create MD5 Hash
            MessageDigest digest = java.security.MessageDigest
                    .getInstance("MD5");
            digest.update(s.getBytes());
            byte messageDigest[] = digest.digest();

            // Create Hex String
            StringBuffer hexString = new StringBuffer();
            for (int i = 0; i < messageDigest.length; i++) {
                String h = Integer.toHexString(0xFF & messageDigest[i]);
                while (h.length() < 2)
                    h = "0" + h;
                hexString.append(h);
            }
            return hexString.toString();

        } catch (NoSuchAlgorithmException e) {
            MoaiLog.e("MoaiAdmob: NoSuchAlgorithmException", e);
        }
        return "";
    }
}