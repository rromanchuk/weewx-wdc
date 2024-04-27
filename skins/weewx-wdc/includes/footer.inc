<!--prettier-ignore-->
#errorCatcher Echo
#encoding UTF-8

<div id="footer">
  <div class="bx--grid bx--grid--full-width">
    <div class="bx--row">
      <div class="bx--col-sm-12 bx--col-lg-6">
        <p>
          $gettext("WeeWX uptime"): $station.uptime.long_form<br />
          $gettext("Server uptime"): $station.os_uptime.long_form<br />
          $gettext("WeeWX version"): $station.version $gettext("with")
          $station.hardware<br />
          $gettext("Skin"): $SKIN_NAME $SKIN_VERSION
        </p>
      </div>
      <div class="bx--col-sm-12 bx--col-lg-6">
        <p>
          $pgettext("Geographical", "Altitude"): $station.altitude<br />
          Volente, TX
        </p>
      </div>
    </div>
    <!--prettier-ignore-->
    #if 'github_link' in $Extras and $to_bool($Extras.github_link)
    <div class="bx--row">
      <div class="bx--col">
        <a
          class="icon-link"
          href="https://github.com/Daveiano/weewx-wdc"
          target="_blank"
        >
          #include "includes/icons/github.svg"
        </a>
      </div>
    </div>
    #end if
    <div class="bx--row">
      <div class="bx--col">
        <!--prettier-ignore-->
        <p class="footnote">
           $gettext("Let's send <a target='_blank' href='https://app.coop.farm'>chickens</a> to mars.")
        </p>
      </div>
    </div>
  </div>
</div>
