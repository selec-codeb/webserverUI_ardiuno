const char index_html[] PROGMEM = R"====( <!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <style>
      body {
        font-family: "Lato", sans-serif;
        width: 100vw;
        height: 100vh;
        overflow: hidden;
      }
       img {
        width: 30vw;
        height: auto;
        margin-right: 10vw;
        float: right;
      }
      
      section {
        display: flex;
        justify-content: center;
        align-items: center;
        width: 100%;
        height: 80%;
      }
      div .sidebar {
        position: absolute;
      }

      .sidenav {
        height: 100%;
        width: 0;
        position: fixed;
        z-index: 1;
        top: 0;
        left: 0;
        background-color: #111;
        overflow-x: hidden;
        transition: 0.5s;
        padding-top: 60px;
      }

      .sidenav a {
        padding: 8px 8px 8px 32px;
        text-decoration: none;
        font-size: 25px;
        color: #818181;
        display: block;
        transition: 0.3s;
      }

      .sidenav a:hover {
        color: #f1f1f1;
      }

      .sidenav .closebtn {
        position: absolute;
        top: 0;
        right: 25px;
        font-size: 36px;
        margin-left: 50px;
      }
      .box {
        border: 2px solid black;
        padding: 39px;
        display: flex;
        justify-content: center;
        align-items: center;
        flex-direction: column;
        display: flex;
      }

      @media screen and (max-height: 450px) {
        .sidenav {
          padding-top: 15px;
        }
        .sidenav a {
          font-size: 18px;
        }
      }
    </style>
  </head>
  <body>
    <div id="mySidenav" class="sidenav">
      <a href="javascript:void(0)" class="closebtn" onclick="closeNav()"
        >&times;</a
      >
      <a href="/">Wifi-Config</a>
      <a href="/setting">Settings</a>
      <a href="#">Help</a>
    </div>
    <span style="font-size: 30px; cursor: pointer" onclick="openNav()"
      >&#9776;</span
    >

    <img src="data:image/jpeg;base64,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" />
    <section>
      <div class="box">
        <form action="/get">
        <div class="row1">
           WIFI_SSID:<br><input type="text" name="ssid">
        </div>
        <div class="row2">
           WIFI_PASSWORD:<br><input type="text" name="password">
        </div>
        <div style="margin: 15px; margin-left: 123px">
          <button type="submit">Submit</button>
        </div>
        </form>
      </div>
    </section>

    <script>
      function openNav() {
        document.getElementById("mySidenav").style.width = "250px";
      }

      function closeNav() {
        document.getElementById("mySidenav").style.width = "0";
      }
    </script>
  </body>
</html>
)====";
