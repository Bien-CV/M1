package webCloud;
import java.io.IOException;
import java.util.Date;

import javax.servlet.http.*;

import com.google.appengine.api.datastore.DatastoreService;
import com.google.appengine.api.datastore.DatastoreServiceFactory;
import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.EntityNotFoundException;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;
import com.google.appengine.api.datastore.PreparedQuery;
import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.Query.*;

import javax.servlet.http.HttpServlet;

import org.datanucleus.store.types.sco.backed.Map;

@SuppressWarnings("serial")
public class Tp2Servlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
		
		DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
/*
		Entity employee = new Entity("Employee");
		Entity employee2 = new Entity("Employee");
		employee.setProperty("firstName", "Antonio");
		employee.setProperty("lastName", "Salieri");
		Date hireDate = new Date();
		employee.setProperty("hireDate", hireDate);
		employee.setProperty("attendedHrTraining", true);
		
		employee2.setProperty("firstName", "Antonio");
		employee2.setProperty("lastName", "Salieri");
		Date hireDate2 = new Date();
		employee.setProperty("hireDate", hireDate2);
		employee2.setProperty("attendedHrTraining", true);
		Key k= KeyFactory.createKey("Dennis", 13031993);
		Entity dede = new Entity(k);
		dede.setProperty("sportPrefere", "escalade");
		dede.setProperty("livrePrefere", "Harry Potter");
		dede.getProperties();*/
		resp.setContentType("text/plain");
		resp.getWriter().println("Hello, world");

		Key k = KeyFactory.createKey("Dennis", 13031993);
		try {
			resp.getWriter().println("----------------");
			resp.getWriter().println(datastore.get(k).getProperties());
		} catch (EntityNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		Filter filtre1 = new FilterPredicate("lastName",FilterOperator.EQUAL, "Salieri");
		Filter filtre2 = new FilterPredicate("firstName", FilterOperator.EQUAL, "Antonio");
		Filter filtre3 =CompositeFilterOperator.and(filtre1, filtre2);
		Query q = new Query("Employee").setFilter(filtre3);
		Query q2 = new Query("Employee").setFilter(filtre1);
		
		PreparedQuery pq = datastore.prepare(q);
		PreparedQuery pq2 = datastore.prepare(q2);
		
		for(Entity e : pq.asIterable()){
			resp.getWriter().println(e.getProperties());
		}
		resp.getWriter().println("-----------------");
		for(Entity e : pq2.asIterable()){
			resp.getWriter().println(e.getProperties());
		}

		
	}
}
