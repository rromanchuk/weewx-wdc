<!--prettier-ignore-->
#encoding UTF-8
#errorCatcher Echo
#import datetime
#set $base_path = $Extras.get("base_path", "./")

<script
  type="module"
  src="https://1.www.s81c.com/common/carbon/web-components/version/v1.27.0/ui-shell.min.js"
></script>
<script
  type="module"
  src="https://1.www.s81c.com/common/carbon/web-components/version/v1.21.0/button.min.js"
></script>

<bx-header aria-label="rromanchuk | $station.location - $current.dateTime">
  <bx-header-menu-button
    button-label-active="Close menu"
    button-label-inactive="Open menu"
  ></bx-header-menu-button>
  <bx-header-name href="$get_base_path(path='index.html')" prefix="">
    <!--prettier-ignore-->
    #include "includes/icons/wdc.svg"
    <span part="prefix" class="bx--header__name--prefix"></span>
    $station.location
  </bx-header-name>
  <bx-header-nav menu-bar-label="Weewx $station.location - $current.dateTime">
    <bx-header-nav-item href="$get_base_path(path='index.html')"
      >$gettext("Today")</bx-header-nav-item
    >
    #if $show_yesterday
    <bx-header-nav-item href="$get_base_path(path='yesterday.html')"
      >$gettext("Yesterday")</bx-header-nav-item
    >
    #end if
    <bx-header-nav-item href="$get_base_path(path='week.html')"
      >$gettext("Week")</bx-header-nav-item
    >
    <bx-header-nav-item href="$get_base_path(path='month.html')"
      >$gettext("Month")</bx-header-nav-item
    >
    <bx-header-nav-item href="$get_base_path(path='year.html')"
      >$gettext("Year")</bx-header-nav-item
    >
  </bx-header-nav>
  <div id="header-global">
    <bx-btn kind="ghost" data-id="theme-toggle"
      >
      <svg
        class="hidden"
        data-id="theme-toggle-light-icon"
        xmlns="http://www.w3.org/2000/svg"
        width="24"
        height="24"
        viewBox="0 0 32 32"
      >
        <path d="M12.6318 25.66C10.2851 25.66 8.14381 25.1173 6.20781 24.032C4.30115 22.9173 2.79048 21.392 1.67581 19.456C0.590479 17.52 0.0478125 15.3787 0.0478125 13.032C0.0478125 9.48267 1.25048 6.52 3.65581 4.144C6.06115 1.768 9.06781 0.58 12.6758 0.58C15.7558 0.58 18.3958 1.47467 20.5958 3.264C22.7958 5.024 24.1891 7.37067 24.7758 10.304H18.3958C17.8678 9.16 17.0905 8.26533 16.0638 7.62C15.0665 6.94533 13.9225 6.608 12.6318 6.608C10.9011 6.608 9.44915 7.224 8.27581 8.456C7.13181 9.688 6.55981 11.228 6.55981 13.076C6.55981 14.924 7.14648 16.4787 8.31981 17.74C9.49315 19.0013 10.9305 19.632 12.6318 19.632C13.9225 19.632 15.0665 19.2947 16.0638 18.62C17.0611 17.916 17.8385 16.9187 18.3958 15.628H24.8638C24.2771 18.6493 22.8691 21.084 20.6398 22.932C18.4105 24.7507 15.7411 25.66 12.6318 25.66ZM40.3958 25.66C37.9611 25.66 35.7611 25.1173 33.7958 24.032C31.8305 22.9467 30.2905 21.4507 29.1758 19.544C28.0905 17.608 27.5478 15.4667 27.5478 13.12C27.5478 9.512 28.7651 6.52 31.1998 4.144C33.6345 1.768 36.6998 0.58 40.3958 0.58C44.0625 0.58 47.1131 1.768 49.5478 4.144C51.9825 6.52 53.1998 9.512 53.1998 13.12C53.1998 16.6987 51.9678 19.6907 49.5038 22.096C47.0691 24.472 44.0331 25.66 40.3958 25.66ZM40.3958 19.632C42.2438 19.632 43.7545 19.0307 44.9278 17.828C46.1011 16.596 46.6878 15.0267 46.6878 13.12C46.6878 11.2133 46.1011 9.65867 44.9278 8.456C43.7545 7.224 42.2291 6.608 40.3518 6.608C38.5038 6.608 36.9931 7.224 35.8198 8.456C34.6465 9.65867 34.0598 11.2133 34.0598 13.12C34.0598 14.0587 34.2065 14.9387 34.4998 15.76C34.8225 16.5813 35.2625 17.2707 35.8198 17.828C36.3771 18.3853 37.0371 18.8253 37.7998 19.148C38.5918 19.4707 39.4571 19.632 40.3958 19.632ZM69.1419 25.66C66.7072 25.66 64.5072 25.1173 62.5419 24.032C60.5766 22.9467 59.0366 21.4507 57.9219 19.544C56.8366 17.608 56.2939 15.4667 56.2939 13.12C56.2939 9.512 57.5112 6.52 59.9459 4.144C62.3806 1.768 65.4459 0.58 69.1419 0.58C72.8086 0.58 75.8592 1.768 78.2939 4.144C80.7286 6.52 81.9459 9.512 81.9459 13.12C81.9459 16.6987 80.7139 19.6907 78.2499 22.096C75.8152 24.472 72.7792 25.66 69.1419 25.66ZM69.1419 19.632C70.9899 19.632 72.5006 19.0307 73.6739 17.828C74.8472 16.596 75.4339 15.0267 75.4339 13.12C75.4339 11.2133 74.8472 9.65867 73.6739 8.456C72.5006 7.224 70.9752 6.608 69.0979 6.608C67.2499 6.608 65.7392 7.224 64.5659 8.456C63.3926 9.65867 62.8059 11.2133 62.8059 13.12C62.8059 14.0587 62.9526 14.9387 63.2459 15.76C63.5686 16.5813 64.0086 17.2707 64.5659 17.828C65.1232 18.3853 65.7832 18.8253 66.5459 19.148C67.3379 19.4707 68.2032 19.632 69.1419 19.632ZM99.56 0.58C103.139 0.58 106.101 1.768 108.448 4.144C110.824 6.52 112.012 9.512 112.012 13.12C112.012 16.728 110.824 19.7347 108.448 22.14C106.072 24.516 103.109 25.704 99.56 25.704C97.1253 25.704 94.94 25.044 93.004 23.724V33.58H86.58V1.24H90.848L91.948 3.396C94.06 1.51867 96.5973 0.58 99.56 0.58ZM94.368 17.784C95.6 19.016 97.14 19.632 98.988 19.632C100.865 19.632 102.42 19.016 103.652 17.784C104.884 16.552 105.5 14.9973 105.5 13.12C105.5 11.888 105.221 10.7733 104.664 9.776C104.107 8.77867 103.329 8.00133 102.332 7.444C101.364 6.88667 100.264 6.608 99.032 6.608C97.8 6.608 96.6853 6.88667 95.688 7.444C94.6907 8.00133 93.9133 8.77867 93.356 9.776C92.828 10.7733 92.564 11.888 92.564 13.12C92.564 14.9973 93.1653 16.552 94.368 17.784Z" fill="#FC6345"/>

      </svg>

      <svg
        class="hidden"
        data-id="theme-toggle-dark-icon"
        xmlns="http://www.w3.org/2000/svg"
        width="24"
        height="24"
        viewBox="0 0 32 32">
        <path d="M12.6318 25.66C10.2851 25.66 8.14381 25.1173 6.20781 24.032C4.30115 22.9173 2.79048 21.392 1.67581 19.456C0.590479 17.52 0.0478125 15.3787 0.0478125 13.032C0.0478125 9.48267 1.25048 6.52 3.65581 4.144C6.06115 1.768 9.06781 0.58 12.6758 0.58C15.7558 0.58 18.3958 1.47467 20.5958 3.264C22.7958 5.024 24.1891 7.37067 24.7758 10.304H18.3958C17.8678 9.16 17.0905 8.26533 16.0638 7.62C15.0665 6.94533 13.9225 6.608 12.6318 6.608C10.9011 6.608 9.44915 7.224 8.27581 8.456C7.13181 9.688 6.55981 11.228 6.55981 13.076C6.55981 14.924 7.14648 16.4787 8.31981 17.74C9.49315 19.0013 10.9305 19.632 12.6318 19.632C13.9225 19.632 15.0665 19.2947 16.0638 18.62C17.0611 17.916 17.8385 16.9187 18.3958 15.628H24.8638C24.2771 18.6493 22.8691 21.084 20.6398 22.932C18.4105 24.7507 15.7411 25.66 12.6318 25.66ZM40.3958 25.66C37.9611 25.66 35.7611 25.1173 33.7958 24.032C31.8305 22.9467 30.2905 21.4507 29.1758 19.544C28.0905 17.608 27.5478 15.4667 27.5478 13.12C27.5478 9.512 28.7651 6.52 31.1998 4.144C33.6345 1.768 36.6998 0.58 40.3958 0.58C44.0625 0.58 47.1131 1.768 49.5478 4.144C51.9825 6.52 53.1998 9.512 53.1998 13.12C53.1998 16.6987 51.9678 19.6907 49.5038 22.096C47.0691 24.472 44.0331 25.66 40.3958 25.66ZM40.3958 19.632C42.2438 19.632 43.7545 19.0307 44.9278 17.828C46.1011 16.596 46.6878 15.0267 46.6878 13.12C46.6878 11.2133 46.1011 9.65867 44.9278 8.456C43.7545 7.224 42.2291 6.608 40.3518 6.608C38.5038 6.608 36.9931 7.224 35.8198 8.456C34.6465 9.65867 34.0598 11.2133 34.0598 13.12C34.0598 14.0587 34.2065 14.9387 34.4998 15.76C34.8225 16.5813 35.2625 17.2707 35.8198 17.828C36.3771 18.3853 37.0371 18.8253 37.7998 19.148C38.5918 19.4707 39.4571 19.632 40.3958 19.632ZM69.1419 25.66C66.7072 25.66 64.5072 25.1173 62.5419 24.032C60.5766 22.9467 59.0366 21.4507 57.9219 19.544C56.8366 17.608 56.2939 15.4667 56.2939 13.12C56.2939 9.512 57.5112 6.52 59.9459 4.144C62.3806 1.768 65.4459 0.58 69.1419 0.58C72.8086 0.58 75.8592 1.768 78.2939 4.144C80.7286 6.52 81.9459 9.512 81.9459 13.12C81.9459 16.6987 80.7139 19.6907 78.2499 22.096C75.8152 24.472 72.7792 25.66 69.1419 25.66ZM69.1419 19.632C70.9899 19.632 72.5006 19.0307 73.6739 17.828C74.8472 16.596 75.4339 15.0267 75.4339 13.12C75.4339 11.2133 74.8472 9.65867 73.6739 8.456C72.5006 7.224 70.9752 6.608 69.0979 6.608C67.2499 6.608 65.7392 7.224 64.5659 8.456C63.3926 9.65867 62.8059 11.2133 62.8059 13.12C62.8059 14.0587 62.9526 14.9387 63.2459 15.76C63.5686 16.5813 64.0086 17.2707 64.5659 17.828C65.1232 18.3853 65.7832 18.8253 66.5459 19.148C67.3379 19.4707 68.2032 19.632 69.1419 19.632ZM99.56 0.58C103.139 0.58 106.101 1.768 108.448 4.144C110.824 6.52 112.012 9.512 112.012 13.12C112.012 16.728 110.824 19.7347 108.448 22.14C106.072 24.516 103.109 25.704 99.56 25.704C97.1253 25.704 94.94 25.044 93.004 23.724V33.58H86.58V1.24H90.848L91.948 3.396C94.06 1.51867 96.5973 0.58 99.56 0.58ZM94.368 17.784C95.6 19.016 97.14 19.632 98.988 19.632C100.865 19.632 102.42 19.016 103.652 17.784C104.884 16.552 105.5 14.9973 105.5 13.12C105.5 11.888 105.221 10.7733 104.664 9.776C104.107 8.77867 103.329 8.00133 102.332 7.444C101.364 6.88667 100.264 6.608 99.032 6.608C97.8 6.608 96.6853 6.88667 95.688 7.444C94.6907 8.00133 93.9133 8.77867 93.356 9.776C92.828 10.7733 92.564 11.888 92.564 13.12C92.564 14.9973 93.1653 16.552 94.368 17.784Z" fill="#FC6345"/>
      </svg>
    </bx-btn>
  </div>
</bx-header>
<bx-side-nav aria-label="Side navigation" collapse-mode="responsive">
  <bx-side-nav-items>
    <bx-side-nav-link
      class="show-small"
      href="$get_base_path(path='index.html')"
      ><span>$gettext("Today")</span></bx-side-nav-link
    >
    #if $show_yesterday
    <bx-side-nav-link
      class="show-small"
      href="$get_base_path(path='yesterday.html')"
      ><span>$gettext("Yesterday")</span></bx-side-nav-link
    >
    #end if
    <bx-side-nav-link class="show-small" href="$get_base_path(path='week.html')"
      ><span>$gettext("Week")</span></bx-side-nav-link
    >
    <bx-side-nav-link
      class="show-small"
      href="$get_base_path(path='month.html')"
      ><span>$gettext("Month")</span></bx-side-nav-link
    >
    <bx-side-nav-link class="show-small" href="$get_base_path(path='year.html')"
      ><span>$gettext("Year")</span></bx-side-nav-link
    >
    <bx-side-nav-divider class="show-small"></bx-side-nav-divider>
    <bx-side-nav-link href="$get_base_path(path='celestial.html')">
      <svg
        slot="title-icon"
        xmlns="http://www.w3.org/2000/svg"
        width="16"
        height="16"
        viewBox="0 0 32 32"
      >
        <defs>
          <style>
            .cls-1 {
              fill: none;
            }
          </style>
        </defs>
        <title>asleep</title>
        <path
          d="M13.5025,5.4136A15.0755,15.0755,0,0,0,25.096,23.6082a11.1134,11.1134,0,0,1-7.9749,3.3893c-.1385,0-.2782.0051-.4178,0A11.0944,11.0944,0,0,1,13.5025,5.4136M14.98,3a1.0024,1.0024,0,0,0-.1746.0156A13.0959,13.0959,0,0,0,16.63,28.9973c.1641.006.3282,0,.4909,0a13.0724,13.0724,0,0,0,10.702-5.5556,1.0094,1.0094,0,0,0-.7833-1.5644A13.08,13.08,0,0,1,15.8892,4.38,1.0149,1.0149,0,0,0,14.98,3Z"
        />
        <rect
          id="_Transparent_Rectangle_"
          data-name="&lt;Transparent Rectangle&gt;"
          class="cls-1"
          width="32"
          height="32"
        />
      </svg>
      <span>$gettext("Celestial")</span>
    </bx-side-nav-link>
    <bx-side-nav-link href="$get_base_path(path='statistics.html')">
      <svg
        slot="title-icon"
        width="16"
        height="16"
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 32 32"
      >
        <defs>
          <style>
            .cls-1 {
              fill: none;
            }
          </style>
        </defs>
        <title>analytics</title>
        <path d="M4,2H2V28a2,2,0,0,0,2,2H30V28H4Z" />
        <path
          d="M30,9H23v2h3.59L19,18.59l-4.29-4.3a1,1,0,0,0-1.42,0L6,21.59,7.41,23,14,16.41l4.29,4.3a1,1,0,0,0,1.42,0L28,12.41V16h2Z"
        />
        <rect
          id="_Transparent_Rectangle_"
          data-name="&lt;Transparent Rectangle&gt;"
          class="cls-1"
          width="32"
          height="32"
        />
      </svg>
      <span>$gettext("Statistics")</span>
    </bx-side-nav-link>

    <!--prettier-ignore-->
    #if $show_sensor_page
    <bx-side-nav-link href="$get_base_path(path='sensor-status.html')">
      <svg
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 32 32"
        slot="title-icon"
        width="16"
        height="16"
      >
        <defs>
          <style>
            .cls-1 {
              fill: none;
            }
          </style>
        </defs>
        <title>$gettext("Sensor Status")</title>
        <rect x="15" y="12" width="2" height="18" />
        <path d="M11.33,18.22a7,7,0,0,1,0-10.44l1.34,1.49a5,5,0,0,0,0,7.46Z" />
        <path
          d="M20.67,18.22l-1.34-1.49a5,5,0,0,0,0-7.46l1.34-1.49a7,7,0,0,1,0,10.44Z"
        />
        <path d="M8.4,21.8a11,11,0,0,1,0-17.6L9.6,5.8a9,9,0,0,0,0,14.4Z" />
        <path
          d="M23.6,21.8l-1.2-1.6a9,9,0,0,0,0-14.4l1.2-1.6a11,11,0,0,1,0,17.6Z"
        />
        <rect
          data-name="&lt;Transparent Rectangle&gt;"
          class="cls-1"
          width="32"
          height="32"
        />
      </svg>
      <span>$gettext("Sensor Status")</span>
    </bx-side-nav-link>
    #end if

    <!--prettier-ignore-->
    #if $show_cmon_page
    <bx-side-nav-link href="$get_base_path(path='computer-monitor.html')">
      <svg
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 32 32"
        slot="title-icon"
        width="16"
        height="16"
      >
        <defs>
          <style>
            .cls-1 {
              fill: none;
            }
          </style>
        </defs>
        <path
          d="M28,16v6H4V6h7V4H4A2,2,0,0,0,2,6V22a2,2,0,0,0,2,2h8v4H8v2H24V28H20V24h8a2,2,0,0,0,2-2V16ZM18,28H14V24h4Z"
          transform="translate(0 0)"
        />
        <path
          d="M18,18h-.01a1,1,0,0,1-.9511-.7253L15.2456,11H11V9h5a1,1,0,0,1,.9615.7252l1.0742,3.7589,3.0088-9.7783A1.0142,1.0142,0,0,1,22,3a.98.98,0,0,1,.9487.6838L24.7207,9H30v2H24a1,1,0,0,1-.9487-.6838l-1.0132-3.04L18.9556,17.2942A1,1,0,0,1,18,18Z"
          transform="translate(0 0)"
        />
        <rect
          data-name="&lt;Transparent Rectangle&gt;"
          class="cls-1"
          width="32"
          height="32"
        />
      </svg>
      <span>$gettext("Computer Monitor")</span>
    </bx-side-nav-link>
    #end if

    <!--prettier-ignore-->
    #for $static_page in $get_static_pages()
    <bx-side-nav-link href="$get_base_path(path=$static_page['link'])">
      <svg
        xmlns="http://www.w3.org/2000/svg"
        slot="title-icon"
        width="16"
        height="16"
        viewBox="0 0 32 32"
      >
        <defs>
          <style>
            .cls-1 {
              fill: none;
            }
          </style>
        </defs>
        <polygon
          points="17 22 17 14 13 14 13 16 15 16 15 22 12 22 12 24 20 24 20 22 17 22"
        />
        <path d="M16,8a1.5,1.5,0,1,0,1.5,1.5A1.5,1.5,0,0,0,16,8Z" />
        <path
          d="M16,30A14,14,0,1,1,30,16,14,14,0,0,1,16,30ZM16,4A12,12,0,1,0,28,16,12,12,0,0,0,16,4Z"
        />
        <rect class="cls-1" width="32" height="32" />
      </svg>
      <span>$gettext($static_page['title'])</span>
    </bx-side-nav-link>
    #end for

    <bx-side-nav-divider></bx-side-nav-divider>
    <bx-side-nav-link class="sidebar-heading"
      ><span>$gettext('Archive & NOAA Reports')</span></bx-side-nav-link
    >
    <!--prettier-ignore-->
    #set $archive_months = $SummaryByMonth
    #if len($SummaryByYear) == 0
    #set $SummaryByYear = $fake_get_report_years($alltime.start.format("%Y"), $latest.dateTime.format("%Y"))
    #end if
    <bx-side-nav-menu title="$gettext('Years')">
      #for $year in $SummaryByYear
      <bx-side-nav-menu-item
        href="$get_base_path(path='year-' + $str(year) + '.html')"
      >
        <b>$year</b>
      </bx-side-nav-menu-item>
      #end for
    </bx-side-nav-menu>
    <!--prettier-ignore-->
    #for $year in $SummaryByYear
    #set $months_for_year = $filter_months(archive_months, $year)
    <!--prettier-ignore-->
    <bx-side-nav-menu title="${year}">
      <!--prettier-ignore-->
      #for $month in $months_for_year
      <bx-side-nav-menu-item href="$get_base_path(path='month-' + $str(month) + '.html')">
        <span>$datetime.datetime.strptime($month, "%Y-%m").strftime("%B")</span>
      </bx-side-nav-menu-item>
      #end for
    </bx-side-nav-menu>
    <!--prettier-ignore-->
    #end for
  </bx-side-nav-items>
</bx-side-nav>

<script>
  // Add 'active' class to nav-items.
  const bxSideNavLinks = document.querySelectorAll(
    "bx-side-nav-link, bx-side-nav-menu-item"
  );

  bxSideNavLinks.forEach((element) => {
    if (
      element.getAttribute("href") &&
      window.location.pathname.includes(
        // Remove leading slash.
        element.getAttribute("href").replace(/^\/+/, "")
      )
    ) {
      element.setAttribute("active", true);
    }
  });
</script>

<script>
  // Default theme.
  const defaultTheme = window.weewxWdcConfig.defaultTheme;

  if (!("weewx.weewx_wdc.color-theme" in localStorage) && defaultTheme !== "auto") {
    localStorage.setItem("weewx.weewx_wdc.color-theme", defaultTheme);
  }

  var themeToggleDarkIcon = document.querySelectorAll(
    '[data-id="theme-toggle-dark-icon"]'
  );
  var themeToggleLightIcon = document.querySelectorAll(
    '[data-id="theme-toggle-light-icon"]'
  );

  // Change the icons inside the button based on previous settings
  if (
    localStorage.getItem("weewx.weewx_wdc.color-theme") === "dark" ||
    (!("weewx.weewx_wdc.color-theme" in localStorage) &&
      window.matchMedia("(prefers-color-scheme: dark)").matches)
  ) {
    document.documentElement.classList.add("dark");
    themeToggleLightIcon.forEach(function (element) {
      element.classList.remove("hidden");
    });
  } else {
    themeToggleDarkIcon.forEach(function (element) {
      element.classList.remove("hidden");
    });
  }

  var themeToggleBtn = document.querySelectorAll('[data-id="theme-toggle"]');

  themeToggleBtn.forEach(function (element) {
    element.addEventListener("click", function () {
      // toggle icons inside button
      themeToggleDarkIcon.forEach(function (element) {
        element.classList.toggle("hidden");
      });
      themeToggleLightIcon.forEach(function (element) {
        element.classList.toggle("hidden");
      });

      // if set via local storage previously
      if (localStorage.getItem("weewx.weewx_wdc.color-theme")) {
        if (localStorage.getItem("weewx.weewx_wdc.color-theme") === "light") {
          document.documentElement.classList.add("dark");
          localStorage.setItem("weewx.weewx_wdc.color-theme", "dark");
        } else {
          document.documentElement.classList.remove("dark");
          localStorage.setItem("weewx.weewx_wdc.color-theme", "light");
        }

        // if NOT set via local storage previously
      } else {
        if (document.documentElement.classList.contains("dark")) {
          document.documentElement.classList.remove("dark");
          localStorage.setItem("weewx.weewx_wdc.color-theme", "light");
        } else {
          document.documentElement.classList.add("dark");
          localStorage.setItem("weewx.weewx_wdc.color-theme", "dark");
        }
      }
    });
  });
</script>

<!--prettier-ignore-->
#if $DisplayOptions.get('layout', 'alternative') == 'classic'
<script>
  const switchSideNavCollapseMode = function () {
    if (window.matchMedia("(min-width: 672px)").matches) {
      document
        .querySelector("bx-side-nav")
        .setAttribute("collapse-mode", "rail");
    } else {
      document
        .querySelector("bx-side-nav")
        .setAttribute("collapse-mode", "responsive");
    }
  };

  switchSideNavCollapseMode();
  window.addEventListener("resize", switchSideNavCollapseMode);
</script>
#end if
