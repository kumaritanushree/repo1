import java.net.*;
import java.io.*;
import java.util.*;
class Client
{
	public static void main(String []ar)
	{
		try{
		InetAddress sockAddr = InetAddress.getByName( "localhost" );
		int port = 5000;
		Socket s= new Socket( sockAddr, port );
		
	
		PrintWriter os = new PrintWriter( s.getOutputStream() );
		BufferedReader is = new BufferedReader( new InputStreamReader( s.getInputStream() ) );
		//String method = ar[0];
		String file = ar[0];
		os.print( "GET " + file + " / HTTP/2.0" + "\r\n\r\n" );
		os.flush();
		String msg, sVersion,fileToOpen = "";
		int code = 0;
		StringTokenizer tokens;
		msg = is.readLine();
		System.out.println("1st line recieved = " + msg);
		tokens = new StringTokenizer(msg);
		sVersion = tokens.nextToken();
		System.out.println("version = " + sVersion);
		try
		{
			String sr = tokens.nextToken();
			System.out.println("code = " +sr);
			code = Integer.parseInt(sr);
		}
		catch(Exception e)
		{
			System.out.println("error occured here");
		}
		is.readLine(); // ignoring date
		is.readLine(); // ignoring server name
		File f;
		FileWriter fis;
		if(code == 200)
		{
			msg = is.readLine();
			tokens = new StringTokenizer(msg); //for file length
			tokens.nextToken(); // ignore the metadata
			int length = Integer.parseInt(tokens.nextToken());// length of coming file
			is.readLine(); //ignoring content type field
			is.readLine(); // pass extra new line
			
			if(file.equals("/"))
				fileToOpen = "index.html";
		//		f = new File(".", "index.html");
			else 
				fileToOpen = file;
		//		f = new File(".", file);
		}

		else if(code == 404)
		{
			is.readLine();// pass content type
			is.readLine(); // pass entra new line
			fileToOpen = "404.html";
		//	f = new File(".", "404.html");
		}

		else if(code == 501)
		{
			is.readLine(); // pass content type
			is.readLine(); // pass extra new line
			fileToOpen = "501.html";
		//	f = new File(".", "501.html");
		}
		f = new File(".", fileToOpen);
		fis = new FileWriter(f);
		int k;
		while( (k = is.read()) != -1)
		{
			fis.write(k);
		}
		fis.close();
		os.close();
		is.close();
		s.close();
		}
		catch( Exception e)
		{
			e.printStackTrace();
		}
	}
}
