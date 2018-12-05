# Supported platforms:

* Android (android platform)
* iOS (ios platform)
* Windows Phone 8.1 (cordova windows platform)
* Windows 8.1 (cordova windows platform)
* Windows 10 (cordova windows platform)

# Using comScore plugin

To add the plugin just run the following command on the project root:

```
cordova plugin add path_to_the_plugin/comScore-Cordova/
```

To remove the plugin run the following:

```
cordova plugin remove com.comscore.cordova
```

Add the following urls the whitelist (config.xml):

```xml
<access origin="*://*.scorecardresearch.com" subdomains="true" />
<access origin="*://*.sitestat.com" subdomains="true" />
```

Once the plugin is installed the first thing that we need to do before using it is  to configure the comScore SDK when the device is ready:
 
```
onDeviceReady: function() {
	//Other stuff

    ns_.comScore.setAppContext({
        'PublisherSecret': '9c455c81a801d3832a2cd281843dff30',
        'CustomerC2': '1000001',
        'AppName': 'PhoneGapTestApp',
        'AppVersion': '1.0.0'
    });
}
```
 
Then we are ready to use it:

```
ns_.comScore.start({});
```