const char index_html[] PROGMEM = R"====( <!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <style>
      body {
        font-family: "Lato", sans-serif;
        width: 100%;
        overflow: hidden;
        background-color: #ece9e6;
        height: 100vh;
        margin: 0;
      }
      @media (max-width: 480px) {
        body {
          height: 90vh;
        }
      }
      img {
        width: 100px;
        height: 20px;
        margin-right: 20px;
        margin-top: 10px;
        float: right;
      }

      section {
        display: flex;
        justify-content: center;
        align-items: center;
        width: 100%;
        height: calc(100% - 70px);
      }
      div .sidebar {
        position: absolute;
      }

      .box {
        box-shadow: 0 2.8px 2.2px rgba(0, 0, 0, 0.034),
          0 6.7px 5.3px rgba(0, 0, 0, 0.048), 0 12.5px 10px rgba(0, 0, 0, 0.06),
          0 22.3px 17.9px rgba(0, 0, 0, 0.072),
          0 41.8px 33.4px rgba(0, 0, 0, 0.086), 0 100px 80px rgba(0, 0, 0, 0.12);
        border-radius: 20px;
        padding: 39px;
        display: flex;
        justify-content: center;
        align-items: center;
        flex-direction: column;
        display: flex;
        background-color: white;
      }

      .nav {
        display: flex;
        height: 50px;
        flex-wrap: wrap;
        list-style: none;
        background-color: #fd8f3a;
        justify-content: center;
        text-decoration: blanchedalmond;
      }

      .nav-pills {
        border: 0;
        border-radius: 0.25rem;
        justify-content: center;
      }

      .nav-link {
        border: 0;
        border-radius: 0.25rem;
        text-decoration: none;
        justify-content: center;
        font-family: Arial, Helvetica, sans-serif;
        font-style: bold;
      }

      .nav-link a:active {
        color: white;
      }
      .nav-link a:hover {
        color: black;
      }
      .nav-fill {
        flex: 1 1 auto;
        text-align: center;
      }

      .nav-item {
        flex: 1 1 auto;
        text-align: center;
        align-self: center;
        content: icon;
      }

      .nav-fill {
        flex: 1 1 auto;
        text-align: center;
        justify-content: center;
      }

      .nav-item {
        flex: 1 1 auto;
        text-align: center;
      }
      ul {
        margin: 0;
        padding: 0 !important;
      }
      .footer {
        position: fixed;
        bottom: 0;
      }
    </style>
  </head>
  <body>
    <img
      src="data:image/jpeg;base64,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"
    />
    <section>
      <div class="box">
        <form action="/get">
          <div class="row1">
            WIFI_SSID:<br /><input type="text" name="ssid" />
          </div>
          <br>
          <div class="row2">
            WIFI_PASSWORD:<br /><input type="text" name="password" />
          </div>
          <div style="margin: 15px; margin-left: 123px">
            <button type="submit">Submit</button>
          </div>
        </form>
      </div>
    </section>
    <footer>
      <ul class="nav nav-pills nav-fill">
        <li class="nav-item">
          <a class="nav-link" aria-current="page" href="/"
            ><svg
              xmlns="http://www.w3.org/2000/svg"
              width="16"
              height="16"
              fill="white"
              class="bi bi-wifi"
              viewBox="0 0 16 16"
            >
              <path
                d="M15.385 6.115a.485.485 0 0 0-.048-.736A12.443 12.443 0 0 0 8 3 12.44 12.44 0 0 0 .663 5.379a.485.485 0 0 0-.048.736.518.518 0 0 0 .668.05A11.448 11.448 0 0 1 8 4c2.507 0 4.827.802 6.717 2.164.204.148.489.13.668-.049z"
              />
              <path
                d="M13.229 8.271c.216-.216.194-.578-.063-.745A9.456 9.456 0 0 0 8 6c-1.905 0-3.68.56-5.166 1.526a.48.48 0 0 0-.063.745.525.525 0 0 0 .652.065A8.46 8.46 0 0 1 8 7a8.46 8.46 0 0 1 4.577 1.336c.205.132.48.108.652-.065zm-2.183 2.183c.226-.226.185-.605-.1-.75A6.472 6.472 0 0 0 8 9c-1.06 0-2.062.254-2.946.704-.285.145-.326.524-.1.75l.015.015c.16.16.408.19.611.09A5.478 5.478 0 0 1 8 10c.868 0 1.69.201 2.42.56.203.1.45.07.611-.091l.015-.015zM9.06 12.44c.196-.196.198-.52-.04-.66A1.99 1.99 0 0 0 8 11.5a1.99 1.99 0 0 0-1.02.28c-.238.14-.236.464-.04.66l.706.706a.5.5 0 0 0 .708 0l.707-.707z"
              /></svg
          ></a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="/setting"
            ><svg
              xmlns="http://www.w3.org/2000/svg"
              width="16"
              height="16"
              fill="white"
              class="bi bi-speedometer"
              viewBox="0 0 16 16"
            >
              <path
                d="M8 2a.5.5 0 0 1 .5.5V4a.5.5 0 0 1-1 0V2.5A.5.5 0 0 1 8 2zM3.732 3.732a.5.5 0 0 1 .707 0l.915.914a.5.5 0 1 1-.708.708l-.914-.915a.5.5 0 0 1 0-.707zM2 8a.5.5 0 0 1 .5-.5h1.586a.5.5 0 0 1 0 1H2.5A.5.5 0 0 1 2 8zm9.5 0a.5.5 0 0 1 .5-.5h1.5a.5.5 0 0 1 0 1H12a.5.5 0 0 1-.5-.5zm.754-4.246a.389.389 0 0 0-.527-.02L7.547 7.31A.91.91 0 1 0 8.85 8.569l3.434-4.297a.389.389 0 0 0-.029-.518z"
              />
              <path
                fill-rule="evenodd"
                d="M6.664 15.889A8 8 0 1 1 9.336.11a8 8 0 0 1-2.672 15.78zm-4.665-4.283A11.945 11.945 0 0 1 8 10c2.186 0 4.236.585 6.001 1.606a7 7 0 1 0-12.002 0z"
              /></svg
          ></a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="#"
            ><svg
              xmlns="http://www.w3.org/2000/svg"
              width="16"
              height="16"
              fill="white"
              class="bi bi-gear"
              viewBox="0 0 16 16"
            >
              <path
                d="M8 4.754a3.246 3.246 0 1 0 0 6.492 3.246 3.246 0 0 0 0-6.492zM5.754 8a2.246 2.246 0 1 1 4.492 0 2.246 2.246 0 0 1-4.492 0z"
              />
              <path
                d="M9.796 1.343c-.527-1.79-3.065-1.79-3.592 0l-.094.319a.873.873 0 0 1-1.255.52l-.292-.16c-1.64-.892-3.433.902-2.54 2.541l.159.292a.873.873 0 0 1-.52 1.255l-.319.094c-1.79.527-1.79 3.065 0 3.592l.319.094a.873.873 0 0 1 .52 1.255l-.16.292c-.892 1.64.901 3.434 2.541 2.54l.292-.159a.873.873 0 0 1 1.255.52l.094.319c.527 1.79 3.065 1.79 3.592 0l.094-.319a.873.873 0 0 1 1.255-.52l.292.16c1.64.893 3.434-.902 2.54-2.541l-.159-.292a.873.873 0 0 1 .52-1.255l.319-.094c1.79-.527 1.79-3.065 0-3.592l-.319-.094a.873.873 0 0 1-.52-1.255l.16-.292c.893-1.64-.902-3.433-2.541-2.54l-.292.159a.873.873 0 0 1-1.255-.52l-.094-.319zm-2.633.283c.246-.835 1.428-.835 1.674 0l.094.319a1.873 1.873 0 0 0 2.693 1.115l.291-.16c.764-.415 1.6.42 1.184 1.185l-.159.292a1.873 1.873 0 0 0 1.116 2.692l.318.094c.835.246.835 1.428 0 1.674l-.319.094a1.873 1.873 0 0 0-1.115 2.693l.16.291c.415.764-.42 1.6-1.185 1.184l-.291-.159a1.873 1.873 0 0 0-2.693 1.116l-.094.318c-.246.835-1.428.835-1.674 0l-.094-.319a1.873 1.873 0 0 0-2.692-1.115l-.292.16c-.764.415-1.6-.42-1.184-1.185l.159-.291A1.873 1.873 0 0 0 1.945 8.93l-.319-.094c-.835-.246-.835-1.428 0-1.674l.319-.094A1.873 1.873 0 0 0 3.06 4.377l-.16-.292c-.415-.764.42-1.6 1.185-1.184l.292.159a1.873 1.873 0 0 0 2.692-1.115l.094-.319z"
              /></svg
          ></a>
        </li>
      </ul>
    </footer>
  </body>
</html>


)====";
