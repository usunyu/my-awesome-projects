package com.spring.sun.test;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import javax.sql.DataSource;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Component;

@Component("offerDao")
public class OfferDao {
	
	private JdbcTemplate jdbc;
	
	@Autowired
	public void setDataSource(DataSource jdbc) {
		this.jdbc = new JdbcTemplate(jdbc);
	}

	public List<Offer> getOffers() {
		return jdbc.query("select * from offers", new RowMapper<Offer>() {
			public Offer mapRow(ResultSet rs, int rowNum) throws SQLException {
				Offer offer = new Offer();
				offer.setId(rs.getInt("id"));
				offer.setName(rs.getString("name"));
				offer.setEmail(rs.getString("email"));
				offer.setText(rs.getString("text"));
				return offer;
			}
		});
	}
}
